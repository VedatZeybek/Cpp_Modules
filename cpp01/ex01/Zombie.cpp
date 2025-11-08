#include "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	setName(name);
}

Zombie::~Zombie()
{
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}

std::string Zombie::getName() const { return (name); }

void	Zombie::setName(std::string name) { this->name = name; }

void	randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}

Zombie*	newZombie(std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}
