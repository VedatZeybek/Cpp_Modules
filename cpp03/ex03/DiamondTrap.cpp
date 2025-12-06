#include "DiamondTrap.hpp"
#include <iostream>
#include "ClapTrap.hpp"


DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), name("Default")
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& n)
	: ClapTrap(n + "_clap_name"), FragTrap(n), ScavTrap(n), name(n)
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(), ScavTrap(), name(other.name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap Assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name
			<< " | ClapTrap name: " << ClapTrap::name << std::endl;
}
