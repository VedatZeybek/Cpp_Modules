#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
	health = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n)
{
	health = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "FragTrap Constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energy > 0 && health > 0)
	{
		std::cout << "FragTrap " << name << " powerfully attacks " << target
				<< ", dealing " << attackDamage << " damage!" << std::endl;
		energy--;
	}
	else
	{
		std::cout << "FragTrap " << name << " has no energy or hit points left to attack." << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}
