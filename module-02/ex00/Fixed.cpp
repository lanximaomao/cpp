#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*  here the operator overload is called */
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if(this != &other) // if they doesnot share the same address
	{
		this->_fixedPoint = other._fixedPoint;
	}
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &output, const Fixed &i)
{
	output << "The value of fixed-point number is: " << i.getRawBits() << std::endl;
	return (output);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

