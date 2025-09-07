#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) 
{
	name = type;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow Meow Meow Meow Meow Meow Meow!" << std::endl;
}
