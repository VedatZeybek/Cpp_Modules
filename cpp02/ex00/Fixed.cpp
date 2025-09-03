#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(Fixed& other)
{
	std::cout << "Copy constructor called" << "\n";
	this->value = other.value;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value = value;
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

