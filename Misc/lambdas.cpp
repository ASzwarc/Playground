#include <iostream>

int main()
{
	int i = 0;

	auto first_lambda = [=]() -> int
	{
		++i;
		std::cout << "Value of i is: " << i << std::endl;
		return i;
	}

	first_lambda();

	return 0;
}