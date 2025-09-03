#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
private:
	int					value;
	static const int	fixed = 8;

public:
	Fixed();
	Fixed(Fixed& fixed);	
	Fixed &operator = (const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw);
};


#endif