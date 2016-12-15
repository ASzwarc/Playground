#include <iostream>

template<typename T, typename S>
auto multiply(T lhs, S rhs) -> decltype(lhs * rhs)
{
	return lhs * rhs;
}


int main()
{
	std::cout << "Multiply result: " << multiply(2, 3.2) << std::endl;
	return 0; 
}