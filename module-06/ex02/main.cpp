#include "Base.hpp"
#include <iostream>

int main()
{
	Base* ptr = generate();
	identify(ptr);
	identify(&(*ptr));
	delete ptr;
	return (0);
}
