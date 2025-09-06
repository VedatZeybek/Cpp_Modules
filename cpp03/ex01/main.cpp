#include "ScavTrap.hpp"

int main()
{
	std::cout << "---- Creating ClapTrap ----\n";
	ClapTrap clap("Clappy");
	clap.attack("enemy");
	clap.printStatus();

	std::cout << "\n---- Creating ScavTrap ----\n";
	ScavTrap scav("Scavy");
	scav.attack("enemy");
	scav.guardGate();
	scav.printStatus();

	std::cout << "\n---- Copying ScavTrap ----\n";
	ScavTrap scavCopy = scav;
	scavCopy.attack("another enemy");
	scavCopy.guardGate();

	std::cout << "\n---- Testing Assignment ----\n";
	ScavTrap scavAssign;
	scavAssign = scav;
	scavAssign.attack("assigned target");

	std::cout << "\n---- End of main ----\n";
	return 0;
}
