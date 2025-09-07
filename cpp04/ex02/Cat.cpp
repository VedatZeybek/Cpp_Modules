#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) 
{
	brain = new Brain();
	name = type;
}

Cat::Cat(const Cat &other) : Animal(other)
{	
	brain = new Brain(*other.brain);
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain; 
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow Meow Meow Meow Meow Meow Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}

