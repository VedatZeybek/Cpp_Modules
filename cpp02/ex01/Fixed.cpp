#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << "\n";
}


//fixed-point representation
//IN THE FIXED NUMBER SYSTEM ------> REAL VALUE = VALUE / 256

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << "\n";
	this->value = other.value;
}

Fixed::Fixed(const int num) 
{
	std::cout << "Int constructor called" << "\n";
	value = num << fixed;
}

//float cannot float bits
Fixed::Fixed(const float num)  //1234.4321      //42.42 
{
	std::cout << "Float constructor called" << "\n";
	value = roundf(num * (1 << fixed));
}

int	Fixed::toInt() const
{
	return ((int)value >> fixed);
}

float Fixed::toFloat() const
{
	return (float) value / (1 << fixed);
}


Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	std::cout << "Copy assignment operator called" << "\n";
	return (*this);
}

void	Fixed::setRawBits( int const raw)
{
	this->value = raw;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << "\n";
	return (value);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}


std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
