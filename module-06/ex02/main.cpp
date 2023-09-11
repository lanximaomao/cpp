#include "Base.hpp"
#include <iostream>

int main()
{
	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;

	return 0;
}
