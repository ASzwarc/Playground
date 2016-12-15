#include <iostream>
#include <string>


struct A {};

std::string to_string(const A& a)
{
	return "I'm an A!";
}

struct B
{
	std::string serialize() const
	{
		return "I'm a B!";
	}
};

struct C
{
	std::string serialize;

};

std::string to_string(const C& c)
{
	return "I'm a C!";
}

struct E
{
	struct Functor
	{
		std::string operator()()
		{
			return "I'm an E!";
		}
	};
	
	Functor serialize;
};

template <class T> struct hasSerialize
{
	typedef char yes[1];
	typedef char no[2];

	template <typename U, U u> struct reallyHas;

	template <typename C> static yes& test(reallyHas<std::string (C::*)(), &C::serialize>*){}
	template <typename C> static yes& test(reallyHas<std::string (C::*)() const, &C::serialize>*){}

	template <typename> static no& test(...){}

	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

int main()
{
	std::cout << std::boolalpha << hasSerialize<A>::value << std::endl;
	std::cout << std::boolalpha << hasSerialize<B>::value << std::endl;
	std::cout << std::boolalpha << hasSerialize<C>::value << std::endl;
	std::cout << std::boolalpha << hasSerialize<E>::value << std::endl;
	return 0;
}