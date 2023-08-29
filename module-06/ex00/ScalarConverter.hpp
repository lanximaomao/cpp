#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
	ScalarConverter();
	//static char	_asChar;
	//static int		_asInt;
	//static float	_asFloat;
	//static double	_asDouble;

	public:
	ScalarConverter(const std::string& str);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void converter(std::string input);
};

# endif
