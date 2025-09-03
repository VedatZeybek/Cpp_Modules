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

	// The 6 comparison operators: >, <, >=, <=, ==, and !=.
	bool operator > (const Fixed &other) const;
	bool operator < (const Fixed &other) const;
	bool operator >= (const Fixed &other) const;
	bool operator <= (const Fixed &other) const;
	bool operator == (const Fixed &other) const;
	bool operator != (const Fixed &other) const;

	//• The 4 arithmetic operators: +, -, *, and /.
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	//The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	~Fixed();
	int	toInt() const;
	float toFloat() const;
	int getRawBits( void ) const;
	void setRawBits( int const raw);

	// member functions
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif