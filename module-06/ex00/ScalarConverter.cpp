#include <iostream>
#include <iomanip>
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

// unknown type?
std::string which_type(const char* str)
{
	bool decimal = false;

	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str == 'f')
			return ("float");
		if (*str == '.')
		{
			decimal = true;
			str++;
		}
		if (!(*str >= '0' && (*str <= '9')))
			return ("char");
		if (*str >= '0' && (*str <= '9'))
			str++;
	}
	if (decimal)
		return ("double");
	return ("int");
}

bool isSpecialChar(std::string& input)
{
	return (input == "nan" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff");
}

bool isPrintableChar(char c)
{
	return ((c >= 32 && c <= 126) ? true : false);
}

void printSpecialChar(std::string& input)
{
	if (input == "nan")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible"  <<std::endl;
		std::cout << "float: " << "nanf"  <<std::endl;
		std::cout << "double: " <<  "nan" <<std::endl;
	}
}

// -inff, +inff and nanf.
// -inf, +inf and nan
// c_str() returns a const char*.
// 42f
// atof: On success, the function returns the converted floating point number as a double value.
// If the converted value would be out of the range of representable values by a double, it causes undefined behavior.
// If no valid conversion could be performed, the function returns zero (0.0).
// how to check overflow
// will the casting create overflow?
void ScalarConverter::converter(std::string& input)
{

	// if it is special strings
	if (isSpecialChar(input))
	{
		printSpecialChar(input);
		return;
	}

	int		asInt;
	char	asChar;
	double	asDouble;
	float	asFloat;

	bool	intOverFlow = false;

	const char* str = input.c_str();
	std::string type = which_type(str);
	std::cout << "\n\nREAL TYPE IS " << type << std::endl << std::endl;
	if (type == "int")
	{
		// convert
		asInt = atoi(str);
		if (std::to_string(asInt) != str)
			intOverFlow = true;
		else
		{
			// cast
			asChar = static_cast<char>(asInt);
			asFloat = static_cast<float>(asInt);
			asDouble = static_cast<double>(asInt);
		}
	}
	else if (type == "float")
	{
		asFloat = atof(str);
		//
		asInt = static_cast<int>(asFloat);
		asChar = static_cast<char>(asFloat);
		asDouble = static_cast<double>(asFloat);
	}
	else if (type == "double")
	{
		asDouble = atof(str);
		//
		asInt =  static_cast<int>(asDouble);
		asChar = static_cast<char>(asDouble);
		asFloat = static_cast<float>(asDouble);
	}
	else if (type == "char")
	{
		asChar = *str;
		//
		asInt = static_cast<int>(asChar);
		asFloat = static_cast<float>(asChar);
		asDouble = static_cast<double>(asChar);
	}

	// printing

	if (isPrintableChar(asChar))
		std::cout << "char: " << asChar << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (!intOverFlow)
		std::cout << "int: " << asInt <<std::endl;
	else
		std::cout << "int: " << "impossible" <<std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << asFloat << "f" <<std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << asDouble <<std::endl;

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
