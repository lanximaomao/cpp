#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout << "Parametric constructor called with an int" << std::endl;
	_fixedPoint = num << _fractionalBits; //?
}

Fixed::Fixed(float const num)
{
	std::cout << "Parametric constructor called with a float" << std::endl;
	_fixedPoint = std::roundf(num * (1 << _fractionalBits));//?
}

Fixed::Fixed(const Fixed & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // here the operator overload is called
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

	if(this != &other) // if they doesnot share the same address
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

std::ostream & operator<<(std::ostream &output, const Fixed &fixed)
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

// operator overload - arithmetic

Fixed Fixed::operator+(const Fixed &other)
{
	return(Fixed(this->_fixedPoint + other.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return(Fixed(this->_fixedPoint - other.getRawBits()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return(Fixed(this->_fixedPoint * other.getRawBits()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return(Fixed(this->_fixedPoint / other.getRawBits()));
}


// //Overload Increment and Decrement Operator
// shallow or deep copy?

Fixed &Fixed::operator++(void)
{
	++this->_fixedPoint;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	return (Fixed((this->getRawBits() + 1)));
}

Fixed Fixed::operator--(int)
{
	return (Fixed((this->getRawBits() - 1)));
}

// what is static and static const?
// why static cannot show here?
// what's the point of having two functions?

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

static const Fixed	&min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

static Fixed		&max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}

static const Fixed	&max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}
