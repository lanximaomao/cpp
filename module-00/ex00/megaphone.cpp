#include <iostream>

/*
**  static_cast is a type of casting operator in C++ that performs
**  compile-time type conversions. It allows you to convert between
**  compatible types explicitly.
**
**  toupper function needs to have an unsigned char type as input
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

