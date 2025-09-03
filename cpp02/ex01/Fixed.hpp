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
	Fixed(const Fixed& fixed);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator = (const Fixed &other);
	~Fixed();
	int	toInt() const;
	float toFloat() const;
	int getRawBits( void ) const;
	void setRawBits( int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif