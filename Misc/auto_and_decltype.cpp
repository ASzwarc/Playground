#include <iostream>
#include <boost/type_index.hpp>

// This wont compile because lhs and rhs are not in scope
// template<typename T, typename S>
// decltype(lhs * rhs) multiplt(T lhs, S rhs)
// {
// 	return lhs * rhs
// }

//Trailing return syntax used to deduce type
template<typename T, typename S>
auto multiply(T lhs, S rhs) -> decltype(lhs * rhs)
{
	return lhs * rhs;
}

//This works with -std=c++14 feature on!
template<typename T, typename S>
auto multiply2(T lhs, S rhs)
{
	return lhs * rhs;
}

struct S
{
	S()
	{
		m_x = 43;
	}
	int m_x;
};


int main()
{
	auto check = {1, 2, 3, 4};
	using namespace boost::typeindex;
	auto zmienna = 3.3;
	std::cout << type_id_with_cvr<decltype(zmienna)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(check)>().pretty_name() << std::endl;
	std::cout << "Multiply result: " << multiply(2, 3.2) << std::endl;
	std::cout << "Multiply2 result:" << multiply2(2, 3.2) << std::endl;
	
	//

	int x;
	const int cx = 42;
	const int& crx = x;
	const S* p = new S();

	auto a = x;
	std::cout << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((x))>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((a))>().pretty_name() << std::endl;
	auto b = cx;
	std::cout << type_id_with_cvr<decltype(cx)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(b)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((cx))>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((b))>().pretty_name() << std::endl;
	auto c = crx;
	std::cout << type_id_with_cvr<decltype(crx)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(c)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((crx))>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((c))>().pretty_name() << std::endl;
	auto d = p->m_x;
	std::cout << type_id_with_cvr<decltype(p->m_x)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(d)>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((p->m_x))>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype((d))>().pretty_name() << std::endl;
	delete p;

	return 0; 
}