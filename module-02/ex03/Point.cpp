#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point(): _x(0), _y(0) {}
Point::~Point() {}

Point::Point(const float x, const float y)
{
	_x = x;
	_y = y;
}

Point::Point(Point &other)
{
	*this = other;
}

Point & Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

float Point::getX() const
{
	return(_x);
}

float Point::getY() const
{
	return (_y);
}

void Point::setX(float x)
{
	_x = x;
}

void Point::setY(float y)
{
	_y = y;
}
