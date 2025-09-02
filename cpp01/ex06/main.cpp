#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Inappropriate argument number.\n";
		return (1);
	}

	std::string str = (av[1]);
	Harl harl;
	harl.complainFromLevel(str);
}
