#include <iostream>
#include "iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	std::cout << "printing int array" << std::endl;
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "print float arrary" << std::endl;
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;
	return (0);
}
