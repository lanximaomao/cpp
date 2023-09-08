#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
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

bool isSpecialChar(const std::string& input)
{
	return (input == "nan" || input == "nanf" ||input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff");
}

std::string ScalarConverter::which_type(const std::string& input)
{
	if (isSpecialChar(input))
		return ("special");

	bool decimal = false;
	const char* str = input.c_str();

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
		if (*str >= '0' && *str <= '9')
			str++;
	}
	if (decimal)
		return ("double");
	return ("int");
}

bool isPrintableChar(char c)
{
	return ((c >= 32 && c <= 126) ? true : false);
}

void ScalarConverter::converter(const std::string& input)
{
	int		asInt = 0;
	char	asChar = 0;
	double	asDouble = 0;
	float	asFloat = 0;

	bool	char_possible = true;
	bool	int_possible = true;
	bool	float_possible = true;
	bool	double_possible = true;

	std::string type = which_type(input);

	if (type == "special")
	{
		char_possible = false;
		int_possible = false;
		if (input == "nan" || input == "nanf")
		{
			asFloat = std::numeric_limits<float>::quiet_NaN();
			asDouble = std::numeric_limits<double>::quiet_NaN();
		}
		else if (input == "+inf" || input == "+inff")
		{
			asFloat = std::numeric_limits<float>::infinity();
			asDouble = std::numeric_limits<double>::infinity();
		}
		else if (input == "-inf" || input == "-inff")
		{
			asFloat = - std::numeric_limits<float>::infinity();
			asDouble = - std::numeric_limits<double>::infinity();
		}
	}
	else if (type == "int")
	{
		asInt = atoi(input.c_str());
		if (std::to_string(asInt) != input)
		{
			int_possible = false;
			float_possible = false;
			double_possible = false;
		}
		else
		{
			asChar = static_cast<char>(asInt);
			asFloat = static_cast<float>(asInt);
			asDouble = static_cast<double>(asInt);
		}
	}
	else if (type == "double" || type == "float")
	{
		asDouble = atof(input.c_str());
		if (asDouble == std::numeric_limits<double>::infinity()
			|| asDouble == - std::numeric_limits<double>::infinity())
		{
			int_possible = false;
			double_possible = false;
			float_possible = false;
		}
		else
		{
			asInt = static_cast<int>(asDouble);
			asFloat = static_cast<float>(asDouble);
			asChar = static_cast<char>(asDouble);
		}
	}
	else if (type == "char")
	{
		asChar = input.c_str()[0];
		asInt = static_cast<int>(asChar);
		asFloat = static_cast<float>(asChar);
		asDouble = static_cast<double>(asChar);
	}
	if (!char_possible)
		std::cout << "char: " << "impossible" <<std::endl;
	else if (!isPrintableChar(asChar))
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << asChar << std::endl;
	if (!int_possible)
		std::cout << "int: " << "impossible" <<std::endl;
	else
		std::cout << "int: " << asInt <<std::endl;
	if (!float_possible)
		std::cout << "float: " << "impossible" <<std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << asFloat << "f" <<std::endl;
	if (!double_possible)
		std::cout << "double: " << "impossible" <<std::endl;
	else
		std::cout << "double: " <<  std::fixed << std::setprecision(1) << asDouble <<std::endl;

}
