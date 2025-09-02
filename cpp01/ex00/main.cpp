#include "Zombie.hpp"

int	main()
{
	Zombie *zombie = newZombie("vzeybek");

	zombie->announce();
	
	randomChump("garslan");

	delete (zombie);
}
