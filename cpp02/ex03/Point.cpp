#include "Point.hpp"

Point::Point() : x(0), y(0) 
{

}

Point::Point(const Fixed a, const Fixed b) : x(a), y(b) 
{
	
}

Point::~Point()
{

}

Fixed  Point::getX() const {return (x); }

Fixed  Point::getY() const {return (y); }


