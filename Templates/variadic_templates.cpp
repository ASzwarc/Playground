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
    int returnCode = func(args...);
    std::cout << returnCode << std::endl;
}

void failed_function()
{
    std::cout << "Failed function!" << std::endl;
}

double failed_something()
{
    return 3.0;
}

int main() {
	execute(func1, 2);
	execute(func2, 3, 4);
	execute(func3, 5, 6, 7);
	// your code goes here

	execute2(func1, 2);
	execute2(func2, 3, 4);
	execute2(func3, 5, 6, 7);

    std::cout << "Failed examples" << std::endl;
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
    /*This will do quite conversion from double to int*/
    execute2(failed_something);
	return 0;
}