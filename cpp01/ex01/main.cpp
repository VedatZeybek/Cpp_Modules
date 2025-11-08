#include "Zombie.hpp"

int main()
{
	Zombie* zombieArmy = zombieHorde(5, "vzeybekarmy");
	
	for (int i = 0; i < 5; i++)
		zombieArmy[i].announce();

	delete[] zombieArmy;
}
