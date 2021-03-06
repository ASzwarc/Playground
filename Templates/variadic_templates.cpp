#include <iostream>

int func1(int param1)
{
	std::cout << "Func1: " << param1  << std::endl;
	return param1;
}

int func2(int param1, int param2)
{
	std::cout << "Func2: " << param1 << ", " << param2 << std::endl;
	return param1;
}

int func3(int param1, int param2, int param3)
{
	std::cout << "Func2: " << param1 << ", " 
			  << param2 << ", " << param3 << std::endl;
	return param1;
}

//How it knows which argument is function name??
template<typename... Args>
void execute(int func(Args...), Args... args)
{
	int returnCode = func(args...);
	std::cout << returnCode << std::endl;
}

template<typename Function, typename...Args>
void execute2(Function func, Args... args)
{
    typedef typename std::result_of<Function(Args...)>::type ReturnType;
    static_assert(std::is_integral<ReturnType>::value, "Function should return integral type!");
    int returnCode = func(args...);
    std::cout << returnCode << std::endl;
}

template<typename Arg, typename Type>
using returns_type = typename std::is_same<typename std::result_of<Arg>::type, Type>;

template<typename Function, typename ...Args>
typename std::enable_if<returns_type<Function(Args...), bool>::value , bool>::type
execute3(Function func, Args... args)
{
    bool returnCode = func(args...);
    std::cout << std::boolalpha << returnCode << std::endl;
    return returnCode;
}

template<typename Function, typename ...Args>
typename std::enable_if<returns_type<Function(Args...), void>::value, void>::type
execute3(Function func, Args... args)
{
    func(args...);
}

template<typename Function, typename ...Args, typename = std::enable_if_t<returns_type<Function(Args...), double>::value>>
void execute4(Function func, Args... args)
{
    func(args...);
    std::cout << "Execute4 was invoked" << std::endl;
}

void failed_function()
{
    std::cout << "Failed function!" << std::endl;
}

double failed_something()
{
    return 3.0;
}

bool should_work(int param1)
{
    std::cout << "Should work" << std::endl;
    return true;
}

int main() {
	execute(func1, 2);
	execute(func2, 3, 4);
	execute(func3, 5, 6, 7);
	// your code goes here

	execute2(func1, 2);
	execute2(func2, 3, 4);
	execute2(func3, 5, 6, 7);

    std::cout << "Fun with enable if" << std::endl;

    execute3(should_work, 1);
    execute3(failed_function);
    
    execute4(failed_something);

    std::cout << "Failed examples" << std::endl;

    /*This example wont work as expected
    execute3(failed_something);
    */

    /*This example wont work because there is no specialization for type that returns void
    execute4(failed_function);
    */

    /*This wont compile because signatures are wrong
    execute(failed_function);
    */
    /* This code won't compile because:
    variadic_templates.cpp: In instantiation of ‘void execute2(Function, Args ...) [with Function = void (*)(); Args = {}]’:
    variadic_templates.cpp:56:29:   required from here
    variadic_templates.cpp:33:34: error: void value not ignored as it ought to be
     int returnCode = func(args...);
                                  ^

    execute2(failed_function);
    */
    /*This will do quiet conversion from double to int*/
    /*After adding static assert this won't compile, it would be better
      to do some sfinae
    execute2(failed_something);
    */
	return 0;
}