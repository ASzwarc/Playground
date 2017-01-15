#include <iostream>
#include <string>
#include <thread>
#include <future>

std::string fun()
{
	std::string str("Hello from async");
	return str;
}

int main()
{
	auto ftr = std::async(&fun);
	std::cout << "Hello from main" << std::endl;
	std::string str = ftr.get();
	std::cout << str << std::endl;
	return 0;
}