#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	int num1 = 10;
	int num2 = 3;
	std::cout << num1/num2 << std::endl; // 3
	std::cout << static_cast<float>(num1/num2) << std::endl; // 3
	std::cout << ((static_cast<float>(num1))/num2) << std::endl; // 3.33333


	Fixed a;
	Fixed const ac;
	std::cout << a << std::endl;

	std::cout << ++a << std::endl;
	Fixed b = a;
	std::cout << b << std::endl;

	Fixed c = a; // 0
	std::cout << a++ << std::endl; // 0
	std::cout << c << std::endl; // 0
	std::cout << a << std::endl; // 0.00390625

	Fixed x( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;

	std::cout << x << std::endl;
	std::cout << Fixed::min( a, x ) << std::endl;
	return 0;
}
