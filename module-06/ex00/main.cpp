#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert char | int | double | floate " << std::endl;
		return (1);
	}

	std::string input = argv[1];
	ScalarConverter::converter(input);

	return (0);
}
