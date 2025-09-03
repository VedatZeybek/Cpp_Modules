#include "Point.hpp"

int main( void )
{
	Fixed a(0.0f);
	Fixed b(0.0f);

	Fixed c(10.0f);
	Fixed d(0.0f);

	Fixed e(0.0f);
	Fixed f(10.0f);

	Point p1(a,  b);
	Point p2(c,  d);
	Point p3(e,  f);

	Fixed x(4.0f);
	Fixed y(4.0f);

	Point test(x, y);

	std::cout << bsp(p1, p2, p3, test) << "\n";
	
	return 0;
}