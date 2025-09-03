#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->energy = 10;
	this->health = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), health(other.health), energy(other.energy), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
{
	this->name = name;
	this->energy = 10;
	this->health = 10;
	this->attackDamage = 0;
	
	std::cout << "Constructor created." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)	
	{
		this->name = other.name;
		this->health = other.health;
		this->energy = other.energy;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return *this; // Zincirleme atama (a = b = c) için gerekli
}


ClapTrap::~ClapTrap()
{
	std::cout << "Constructor destroyed." << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks "  << target << " causing "
			  << attackDamage << " points of damage!" << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	health += amount;
	energy--;
}

// Getters
std::string ClapTrap::getName() const { return name; }
int ClapTrap::getHealth() const { return health; }
int ClapTrap::getEnergy() const { return energy; }
int ClapTrap::getAttackDamage() const { return attackDamage; }

// Setters
void ClapTrap::setName(const std::string& newName) { name = newName; }
void ClapTrap::setHealth(int newHealth) { health = newHealth; }
void ClapTrap::setEnergy(int newEnergy) { energy = newEnergy; }
void ClapTrap::setAttackDamage(int newAttackDamage) { attackDamage = newAttackDamage; }
