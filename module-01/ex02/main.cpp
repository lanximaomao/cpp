#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::setw(30) << std::left << "memory address of str: " << std::setw(20) << std::right << &str << std::endl;
	std::cout << std::setw(30) << std::left << "memory address of stringPTR: " << std::setw(20) << std::right << stringPTR << std::endl;
	std::cout << std::setw(30) << std::left << "memory address of stringREF: " << std::setw(20) << std::right << &stringREF << std::endl;
	std::cout << std::setw(30) << std::left << "value of string: " << std::setw(20) << std::right << str << std::endl;
	std::cout << std::setw(30) << std::left << "value pointed by stringPTR: " << std::setw(20) << std::right << *stringPTR << std::endl;
	std::cout << std::setw(30) << std::left << "value pointed by stringREF: " << std::setw(20) << std::right << stringREF << std::endl;

	return(0);
}
