#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPoint(0) { }

/* num *= 2 ^ 8*/
Fixed::Fixed(const int num)
{
	_fixedPoint = num << _fractionalBits;
}

/* num *= 2 ^ 8*/
Fixed::Fixed(const float num)
{
	_fixedPoint = std::roundf(num * (1 << _fractionalBits));
}

/* here the operator overload is called */
Fixed::Fixed(const Fixed & other)
{
	*this = other;
}

float Fixed::toFloat() const
{
	float val = static_cast<float>(this->_fixedPoint) / (1 << _fractionalBits);
	return (val);
}

int	Fixed::toInt() const
{
	return (_fixedPoint >> _fractionalBits);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if(this != &other) // if they doesnot share the same address
		setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

// operator overload - comparison
bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return(this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return(this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return(this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->getRawBits() != other.getRawBits());
}

// operator overload - arithmetic - create new object
Fixed Fixed::operator+(const Fixed &other)
{
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	return(Fixed( f1 + f2 ));
}

Fixed Fixed::operator-(const Fixed &other)
{
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	return(Fixed( f1 - f2 ));
}

Fixed Fixed::operator*(const Fixed &other)
{
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	return(Fixed( f1 * f2 ));
}

Fixed Fixed::operator/(const Fixed &other)
{
	float f1 = this->toFloat();
	float f2 = other.toFloat();
	return(Fixed( f1 / f2 ));
}


// Overload Increment and Decrement Operator
// pre- is shallow copy and post- is deep copy

Fixed&	Fixed::operator++() // pre-increment
{
	++this->_fixedPoint;
	return (*this);
}

Fixed&	Fixed::operator--() // pre-decrement
{
	--this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int) // post-increment
{
	Fixed old = *this;
	++this->_fixedPoint;
	return (old);
}

Fixed Fixed::operator--(int)  // post-decrement
{
	Fixed old = *this;
	--this->_fixedPoint;
	return (old);
}

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}

std::ostream& operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}
