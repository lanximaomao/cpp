#include "Array.hpp"
#include <iostream>

#define MAX_SIZE 12

int main()
{
	std::cout << "\n\n=====  basic functionality test =====\n\n";
	Array<int> test_random = Array<int>(MAX_SIZE);
	int* a = new int(MAX_SIZE);
	srand(time(NULL));
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		int random_value = rand();
		test_random.getArray()[i] = random_value;
		a[i] = random_value;
	}
	for (size_t i = 0; i < MAX_SIZE; i++)
		std::cout << test_random.getArray()[i] << " ";
	std::cout << std::endl;

	std::cout << "\n\n=====  deep copy test =====\n\n";
	Array<int> test_empty = Array<int>(0);
	std::cout << "old size = " << test_empty.size() << std::endl;
	test_empty = test_random;
	std::cout << "new size = " << test_empty.size() << std::endl;
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		if (test_empty.getArray()[i] != test_random.getArray()[i])
		{
			std::cout << "**** copy test failed.**** " << std::endl;
		}
	}
	std::cout << "***** copy test successful.*****" << std::endl;

	std::cout << "\n\n=====  exception test =====\n\n";
	try
	{
		test_empty[1] = 12;
	}
	catch(const std::exception& ex)
	{
		std::cerr << "cannot access an empty array: " << ex.what() << std::endl;
	}
	try
	{
		test_random[12] = 12;
	}
	catch(const std::exception& ex)
	{
		std::cerr << "cannot access an index which is out of range: " << ex.what() << std::endl;
	}
	return (0);
}
