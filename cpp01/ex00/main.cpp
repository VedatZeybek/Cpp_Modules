#include "Zombie.hpp"

int	main()
{
	Zombie *zombie = newZombie("vzeybek");

	zombie->announce();
	
	randomChump("harici");

	delete (zombie);
}
