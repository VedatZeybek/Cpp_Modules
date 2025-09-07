#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Constructor Called!" << std::endl;
}

Animal::Animal(const std::string& type)
{
	name = type;
}

Animal::Animal(Animal &other)
{
	std::cout << "Animal Copy Constructor Called!" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
}

Animal& Animal::operator=(const Animal &other)
{	
	std::cout << "Animal Copy Assigment Constructor Called!" << std::endl;
	this->name = other.name;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called!" << std::endl;
}


void Animal::makeSound() const
{
    std::cout << "I am a generic Animal" << std::endl;
}


std::string Animal::getType() const
{
	return (name);
}
