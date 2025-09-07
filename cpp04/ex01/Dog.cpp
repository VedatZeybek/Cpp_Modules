#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) 
{
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Haw Haw Haw Haw Haw Haw Haw Haw Haw!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}

