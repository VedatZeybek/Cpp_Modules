#include "ClapTrap.hpp"


int	main()
{
	ClapTrap clap = ClapTrap("Vedat");
	clap.attack("zombie");
	std::cout << "Health: " << clap.getHealth()
			  << " Energy: " << clap.getEnergy() << std::endl;
	clap.beRepaired(10);
	std::cout << "Health: " << clap.getHealth()
			  << " Energy: " << clap.getEnergy() << std::endl;
	clap.takeDamage(5);
	std::cout << "Health: " << clap.getHealth()
			  << " Energy: " << clap.getEnergy() << std::endl;
}