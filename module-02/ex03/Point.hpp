#ifndef POINT_HPP
# define POINT_HPP

class Point
{
	private:
		float	_x;
		float	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point &other);
		Point &operator=(const Point &other);
		~Point();

		float getX() const;
		float getY() const;
		void setX(float x);
		void setY(float y);
};

Point::Point(void): _x(0), _y(0) {}
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

Point &Point::operator=(const Point &other)
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

#endif
