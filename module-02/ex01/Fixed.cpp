#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout << "Parametric constructor called with an int" << std::endl;
	_fixedPoint = num << _fractionalBits;
}

Fixed::Fixed(float const num)
{
	std::cout << "Parametric constructor called with a float" << std::endl;
	_fixedPoint = std::roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

float Fixed::toFloat(void) const
{
	float val = static_cast<float>(this->_fixedPoint) / (1 << _fractionalBits);
	return (val);
}

int	Fixed::toInt(void) const
{
	return (_fixedPoint >> _fractionalBits);
}

Fixed & Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if(this != &other)
		setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

std::ostream& operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

