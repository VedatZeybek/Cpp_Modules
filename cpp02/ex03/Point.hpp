#ifndef POINT_HPP
#define POINT_HPP

#include "iostream"
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Fixed a, const Fixed b);
	Point& operator=(const Point& other);
	Fixed  getX() const;
	Fixed  getY() const;
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif