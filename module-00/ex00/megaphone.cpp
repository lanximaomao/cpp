#include <iostream>

/*
** static_cast is a type of casting operator in C++ that performs compile-time type conversions.
** It allows you to convert between compatible types explicitly.
**
** Noted that the std::toupper function takes unsigned char as an input and returns an integer.
** By giving an negative value to toupper, it will not create exception but will exhibit undefined behavior.
** To convert the returned value back to a character, you can simply assign it to a char variable.
*/

int main(int argc, char** argv)
{
	int i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		for(int j = 0; j < (int)strlen(argv[i]); j++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
		if (i + 1 < argc)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}

