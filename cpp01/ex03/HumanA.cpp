#include "HumanA.hpp"

void		HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

HumanA::~HumanA()
{
}

