#include "Point.hpp"

float abs(float num) { return (num < 0 ? -num : num); }

float getArea( Point const p1, Point const p2, Point const p3 )
{
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();
	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();
	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0f);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area = getArea(a, b, c);
	float area1 = getArea(point, b, c);
	float area2 = getArea(a, point, c);
	float area3 = getArea(a, b, point);

	if ((area1 && area2 && area3) != 1)
		return false;

	if (area == area1 + area2 + area3)
		return (true);
	
	return (false);
}
