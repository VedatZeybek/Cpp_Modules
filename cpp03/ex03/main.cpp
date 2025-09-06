#include "DiamondTrap.hpp"

int main()
{
	std::cout << "---- Creating DiamondTrap ----" << std::endl;
	DiamondTrap dia("Diamondy");

	dia.printStatus();
	dia.attack("target dummy");
	dia.whoAmI();

	std::cout << "\n---- Copy + Assignment ----" << std::endl;
	DiamondTrap copyDia(dia);
	copyDia.whoAmI();

	DiamondTrap assignDia;
	assignDia = dia;
	assignDia.whoAmI();

	std::cout << "\n---- End of main ----" << std::endl;
	return 0;
}
