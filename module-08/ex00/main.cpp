#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>
#include <iostream>

template <typename T>
void test(T& v1)
{
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	try
	{
		std::cout << *easyfind(v1, 1) << std::endl;
		std::cout << *easyfind(v1, 2) << std::endl;
		std::cout << *easyfind(v1, 30) << std::endl;
	}
	catch(ValueNotFound& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

int main()
{
	std::cout << "\n\n=====  test in vector =====\n\n";
	std::vector<int> v1;
	test(v1);

	std::cout << "\n\n=====  test easyfind with list =====\n\n";
	std::list<int> l1;
	test(l1);

	std::cout << "\n\n=====  test easyfind with stack =====\n\n";
	std::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);

	try
	{
		std::cout << *easyfind(v1, 1) << std::endl;
		std::cout << *easyfind(v1, 2) << std::endl;
		std::cout << *easyfind(v1, 30) << std::endl;
	}
	catch(ValueNotFound& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return (0);
}
