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

template<typename... Args>
void execute(int func(Args...), Args... args)
{
	int returnCode = func(args...);
	std::cout << returnCode << std::endl;
}

int main() {
	execute(func1, 2);
	execute(func2, 3, 4);
	execute(func3, 5, 6, 7);
	// your code goes here
	return 0;
}