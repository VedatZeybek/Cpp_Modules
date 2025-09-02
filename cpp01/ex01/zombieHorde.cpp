#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	i;

	i = 0;
	Zombie *zombie;
	while (i < N)
	{
		zombie = newZombie(name);
		zombie->announce();
		i++;
	}
	return (zombie);
}
