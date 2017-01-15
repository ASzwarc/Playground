#include <iostream>
#include <utility>

int main()
{
	auto fibonacci_lambda = [i = 0, j = 1]() mutable {
		i = std::exchange(j, j + i);
		return i;
	};

	for(int i = 0 ; i < 10 ; ++i)
	{
		std::cout << fibonacci_lambda() << std::endl;
	}
	return 0;
}