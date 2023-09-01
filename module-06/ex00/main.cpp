#include <iostream>

#include "ScalarConverter.hpp"

//static char	_asChar = 0;
//static int		_asInt = 0;
//static float	_asFloat = 0;
//static double	_asDouble = 0;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert char | int | double | floate " << std::endl;
		return (1);
	}

	//std::string input = argv[1];
	ScalarConverter::converter(argv[1]);

	return (0);
}
