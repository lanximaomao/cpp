#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

//Barycentric coordinates

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float u;
	float v;
	float w;

	u = ((b.getY() - c.getY())*(point.getX() - c.getX()) + (c.getX() - b.getX())*(point.getY() - c.getY())) / ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	v = ((c.getY() - a.getY())*(point.getX() - c.getX()) + (a.getX() - c.getX())*(point.getY() - c.getY())) / ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	w = 1 - u - v;
	return (u >= 0.0 && v >= 0.0 && w >= 0.0 && u <= 1.0 && v <= 1.0 && w <= 1.0);
}


int main( void )
{

	Point p(2, 2);
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 4);

	if (bsp(a, b, c, p))
		std::cout << "Point inside triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;
	return 0;
}
