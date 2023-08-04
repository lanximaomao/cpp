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

#endif
