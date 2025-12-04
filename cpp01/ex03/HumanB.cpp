#include "HumanB.hpp"

void HumanB::attack()
{
    if (!weapon) {
        std::cout << name << " has no weapon!\n";
        return;
    }
    std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
