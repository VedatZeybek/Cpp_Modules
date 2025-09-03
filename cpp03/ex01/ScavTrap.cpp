#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{

}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::~ ScavTrap()
{
}
