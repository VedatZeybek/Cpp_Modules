#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	setName(name);
}

Zombie::~Zombie()
{
	std::cout 	<< getName()
				<< ": called destructor."
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}

std::string Zombie::getName() const { return (name1); }

void	Zombie::setName(std::string name) { this->name = name; }
