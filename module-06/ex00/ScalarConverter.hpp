#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum ScalarType
{
	Special,
	Valid_input,
	Invalid_input
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void converter(const std::string& input);
};

# endif
