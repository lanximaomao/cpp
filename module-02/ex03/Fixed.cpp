#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPoint(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

// left shift by 8 bits so that the fractional part is all zeros.
Fixed::Fixed(const int num)
{
	//std::cout << "Parametric constructor called with an int" << std::endl;
	_fixedPoint = num << _fractionalBits;
}

// num * 2^8
Fixed::Fixed(const float num)
{
	//std::cout << "Parametric constructor called with a float" << std::endl;
	_fixedPoint = std::roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed & other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other; // here the operator overload is called
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
	//std::cout << "Copy assignment operator called" << std::endl;

	if(this != &other) // if they doesnot share the same address
		setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
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
