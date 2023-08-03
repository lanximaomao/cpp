#include "Fixed.hpp"

Fixed::Fixed(void): _num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // here the operator overload is called
}

Fixed & Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if(this != &other) // if they doesnot share the same address
	{
		this->_num = other._num;
	}
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream & operator<<(std::ostream &output, const Fixed &i)
{
	output << "The value of fixed-point number is: " << i.getRawBits() << std::endl;
	return (output);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void Fixed::setRawBits(int const raw)
{
	_num = raw;
}

