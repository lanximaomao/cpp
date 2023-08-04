#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// Barycentric coordinates
// as per subject, any point on the edges of the triangles are treated as outside
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float u;
	float v;
	float w;

	u = ((b.getY() - c.getY())*(point.getX() - c.getX()) + (c.getX() - b.getX())*(point.getY() - c.getY()))
		/ ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	v = ((c.getY() - a.getY())*(point.getX() - c.getX()) + (a.getX() - c.getX())*(point.getY() - c.getY()))
		 / ((b.getY() - c.getY())*(a.getX() - c.getX()) + (c.getX() - b.getX())*(a.getY() - c.getY()));
	w = 1 - u - v;
	return (u > 0.0 && v > 0.0 && w > 0.0 && u < 1.0 && v <1.0 && w < 1.0);
}


int main( void )
{

	Point p(3, 1);
	Point a(1, 1);
	Point b(3, 3);
	Point c(4, 0);

	if (bsp(a, b, c, p))
		std::cout << "Point inside triangle" << std::endl;
	else
		std::cout << "Point outside triangle" << std::endl;
	return 0;
}
