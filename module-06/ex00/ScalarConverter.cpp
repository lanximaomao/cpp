#include <iostream>
#include <cstdlib>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& str)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	return(*this);
}

std::ostream& operator<<(std::ostream& out, ScalarConverter& s)
{
	return (out);
}

// ss.clear() is to clear any error floags that might have been set on the stream.
// it is not used to clear the contents of the stream.

//

void ScalarConverter::converter(std::string input)
{
	int asInt = atoi(input.c_str());
	char asChar = *(input.c_str());
	double asDouble = atof(input.c_str());
	float asFloat = atof(input.c_str());

	std::cout << "char: " << asChar <<std::endl;
	std::cout << "int: " << asInt <<std::endl;
	std::cout << "float: " << asFloat <<std::endl;
	std::cout << "double: " << asDouble <<std::endl;

	// -inff, +inff and nanf.
	// -inf, +inf and nan
}

//./convert 0
//char: Non displayable
//int: 0
//float: 0.0f
//double: 0.0
//./convert nan
//char: impossible
//int: impossible
//float: nanf
//double: nan
//./convert 42.0f
//char: '*'
//int: 42
//float: 42.0f
//double: 42.0
