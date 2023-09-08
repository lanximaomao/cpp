#include "Base.hpp"
#include <iostream>
#include <ctime>

Base::~Base() {}

Base* generate(void)
{
	srand(time(NULL));
	int random_variable = std::rand() % 3;
	if (random_variable == 0) return (new A);
	if (random_variable == 1) return (new B);
	if (random_variable == 2) return (new C);
	return (NULL);
}

void identify(Base* p)
{
	std::string type;

	if (dynamic_cast<A*>(p)) type = "A";
	else if (dynamic_cast<B*>(p)) type = "B";
	else if (dynamic_cast<C*>(p)) type = "C";

	std::cout << "type is " << type << std::endl;
}

void identify(Base& p)
{
	std::string type = "unknow";
	try
	{
		(void)dynamic_cast<A&>(p);
		type = "A";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		type = "B";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		type = "C";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "type is " << type << std::endl;
}
