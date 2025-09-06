#include "FragTrap.hpp"

int main()
{
	std::cout << "---- Creating ClapTrap ----\n";
	ClapTrap clap("Clappy");
	clap.attack("vzeybek");
	clap.printStatus();

	std::cout << "\n---- Creating FragTrap ----\n";
	FragTrap frag("Frag Frag");
	frag.attack("garslan");
	frag.highFivesGuys();
	frag.printStatus();

	std::cout << "\n---- Copying FragTrap ----\n";

	FragTrap copy_frag = frag;
	copy_frag.attack("Griffith");
	copy_frag.highFivesGuys();
	copy_frag.printStatus();

	std::cout << "\n---- End of main ----\n";
	return 0;
}
