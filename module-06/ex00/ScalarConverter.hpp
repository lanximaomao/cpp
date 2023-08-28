#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	char	_asChar;
	int		_asInt;
	float	_asFloat;
	double	_asDouble;

public:
	ScalarConverter(const std::string& str);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void converter(std::string input);
};

# endif
