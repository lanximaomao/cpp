#include <iostream>
#include <sstream>

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

void ScalarConverter::converter(std::string input)
{
	std::stringstream ss(input);

	int asInt = 0;
	char asChar = 'a';
	double asDouble = 0.0;
	float asFloat = 0.0;

	ss >> asChar;
	ss.clear();
	ss.seekg(0);

	ss >> asInt;
	ss.clear();
	ss.seekg(0);

	ss >> asFloat;
	ss.clear();
	ss.seekg(0);

	ss >> asDouble;
	ss.clear();
	ss.seekg(0);

	std::cout << "char: " << asChar <<std::endl;
	std::cout << "int: " << asInt <<std::endl;
	std::cout << "float: " << asFloat <<std::endl;
	std::cout << "double: " << asDouble <<std::endl;

}
