#include "Harl.hpp"

void	Harl::debug( void ) {std::cout << DEBUG << "\n";}	
void	Harl::info( void ) {std::cout << INFO << "\n";}
void	Harl::warning( void ) {std::cout << WARNING << "\n";}
void	Harl::error( void ) {std::cout << ERROR << "\n";}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "\n";
}

Harl::Harl()
{
}

Harl::~Harl()
{
}