#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) 
{
	name = type;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Haw Haw Haw Haw Haw Haw Haw Haw Haw!" << std::endl;
}
