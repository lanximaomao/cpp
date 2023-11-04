#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}

	if (RPN::calculateRPN(argv[1]))
		std::cout << RPN::_rpn.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
	return (0);
}


//$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
//42
//$> ./RPN "7 7 * 7 -"
//42
//$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
//0
//$> ./RPN "(1 + 1)"
//Error
//$>
