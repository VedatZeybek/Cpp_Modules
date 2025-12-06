#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	health = 100;
	energy = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
{
    health = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Parameterized constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap Assignment operator called\n";
	return *this;
}

ScavTrap::~ ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (energy > 0 && health > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\n";
        energy--;
    } else {
        std::cout << "ScavTrap " << name << " has no energy or hit points left to attack.\n";
    }
}