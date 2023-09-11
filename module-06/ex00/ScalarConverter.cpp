#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return(*this);
}

static bool isSpecialChar(const std::string& input)
{
	return (input == "nan" || input == "nanf"
		||input == "inf" || input == "inff" || input == "+inf"
		|| input == "+inff" || input == "-inf" || input == "-inff");
}

static int which_type(const std::string& input)
{
	if (isSpecialChar(input))
		return (Special);

	bool hasDecimal = false;
	bool hasFloatSpecifier = false;
	const char* str = input.c_str();

	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!hasFloatSpecifier && *str == 'f')
		{
			hasFloatSpecifier = true;
			if ((*(str+1)))
				return Invalid_input;
			return (Valid_input);
		}
		if (hasFloatSpecifier && *str == 'f')
			return (Invalid_input);

		if (!hasDecimal && *str == '.')
		{
			hasDecimal = true;
			str++;
		}
		if (hasDecimal && *str == '.')
			return (Invalid_input);

		if (!(*str >= '0' && (*str <= '9')))
			return (Invalid_input);
		if (*str >= '0' && *str <= '9')
			str++;
	}
	return (Valid_input);
}

static bool isPrintableChar(char c)
{
	return ((c >= 32 && c <= 126) ? true : false);
}

static void print_error_msg()
{
	std::cout << "char: " << "impossible" <<std::endl;
	std::cout << "int: " << "impossible" <<std::endl;
	std::cout << "float: " << "impossible" <<std::endl;
	std::cout << "double: " << "impossible" <<std::endl;
}

static void print_special_msg(const std::string& input)
{

	std::cout << std::left << std::setw(10) << "char: " << "impossible" <<std::endl;
	std::cout << std::left << std::setw(10) << "int: " << "impossible" <<std::endl;
	if (input == "nan" || input == "nanf")
	{
		std::cout << std::left << std::setw(10) << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" <<std::endl;
		std::cout << std::left << std::setw(10) << "double: " << std::numeric_limits<double>::quiet_NaN() <<std::endl;
	}
	else if (input == "inf" || input == "+inf" || input == "+inff")
	{
		std::cout << std::left << std::setw(10) << "float: " << std::numeric_limits<float>::infinity() << "f" <<std::endl;
		std::cout << std::left << std::setw(10) << "double: " << std::numeric_limits<double>::infinity() <<std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << std::left << std::setw(10) << "float: " << - std::numeric_limits<float>::infinity() << "f" <<std::endl;
		std::cout << std::left << std::setw(10) << "double: " << - std::numeric_limits<double>::infinity() <<std::endl;
	}
}

static void printChar(double asDouble)
{
	if (asDouble < std::numeric_limits<char>::min() || asDouble > std::numeric_limits<char>::max())
		std::cout << "char: impossible" <<std::endl;//?
	else
	{
		char asChar = static_cast<char>(asDouble);
		if (!isPrintableChar(asChar))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << asChar << std::endl;
	}
}

static void printInt(double asDouble)
{
	if (asDouble > std::numeric_limits<int>::max() || asDouble < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		int asInt = static_cast<int>(asDouble);
		std::cout << "int: " << asInt << std::endl;
	}
}

static void printFloat(double asDouble)
{
	if (asDouble > std::numeric_limits<float>::max() || asDouble < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		float asFloat = static_cast<float>(asDouble);
		std::cout << "float: " << asFloat << "f" << std::endl;
	}
}

static void printDouble(double asDouble)
{
	std::cout << "double: " << asDouble <<std::endl;
}

void ScalarConverter::converter(const std::string& input)
{
	int type = which_type(input);
	if (type == Invalid_input)
		print_error_msg();
	else if (type == Special)
		print_special_msg(input);
	else
	{
		double asDouble = 0;
		try
		{
			asDouble = stod(input);
		}
		catch(...)
		{
			print_error_msg();
			return;
		}
		if (asDouble == std::numeric_limits<double>::infinity() // overflow
			|| asDouble == - std::numeric_limits<double>::infinity())
			print_error_msg();
		else
		{
			printChar(asDouble);
			printInt(asDouble);
			printFloat(asDouble);
			printDouble(asDouble);
		}
	}
}
