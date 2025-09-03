#include "Fixed.hpp"
#include <cmath>

// Member FUnctions


Fixed& Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }


// The 6 comparison operators: >, <, >=, <=, ==, and !=.

bool Fixed::operator > (const Fixed &other) const { return (this->getRawBits() > other.getRawBits()); }

bool Fixed::operator < (const Fixed &other) const{ return (this->getRawBits() < other.getRawBits()); }

bool Fixed::operator >= (const Fixed &other) const { return (this->getRawBits() >= other.getRawBits()); }

bool Fixed::operator <= (const Fixed &other) const { return (this->getRawBits() <= other.getRawBits()); }

bool Fixed::operator == (const Fixed &other) const { return (this->getRawBits() == other.getRawBits()); }

bool Fixed::operator != (const Fixed &other) const { return (this->getRawBits() != other.getRawBits()); }


//• The 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator + (const Fixed &other) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() + other.getRawBits());
	return (newFixed);
}

Fixed Fixed::operator - (const Fixed &other) const
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() - other.getRawBits());
	return (newFixed);
}

Fixed Fixed::operator * (const Fixed &other) const
{
	Fixed newFixed;
	long temp = ((long)this->getRawBits() * (long)other.getRawBits());
	newFixed.setRawBits(temp >> fixed);
	return (newFixed);
}

Fixed Fixed::operator / (const Fixed &other) const
{
	Fixed newFixed;
    long temp = ((long)this->getRawBits() << fixed) / (long)other.getRawBits();
    newFixed.setRawBits(temp);
	return (newFixed);
}

//The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return (temp);
}

// Constructor 

Fixed::Fixed()
{
	value = 0;
	//std::cout << "Default constructor called" << "\n";
}

// Copy Constructors

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << "\n";
	this->value = other.value;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << "\n";
	value = num << fixed;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << "\n";
	value = roundf(num * (1 << fixed));
}


//Assignemnt Operator overloaded

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}	
	//std::cout << "Copy assignment operator called" << "\n";
	return (*this);
}	

//Destructor

Fixed::~Fixed()
{
	//td::cout << "Destructor called" << "\n";
}

// Member Functions

int	Fixed::toInt() const
{
	return ((int)value >> fixed);
}

float Fixed::toFloat() const
{
	return (float) value / (1 << fixed);
}

void	Fixed::setRawBits( int const raw)
{
	this->value = raw;
}	

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << "\n";
	return (value);
}	

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
