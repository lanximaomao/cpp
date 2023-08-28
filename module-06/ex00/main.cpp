#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		std::cout << "Usage: ./scalar char | int | double | floate " << std::endl;

	//std::string input = argv[1];
	ScalarConverter::converter(argv[1]);

	return (0);
}
