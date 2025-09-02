#include "Harl.hpp"

void	Harl::debug( void ) {std::cout << DEBUG << "\n";}	
void	Harl::info( void ) {std::cout << INFO << "\n";}
void	Harl::warning( void ) {std::cout << WARNING << "\n";}
void	Harl::error( void ) {std::cout << ERROR << "\n";}

enum Level { D = 1, I, W, E, UNKNOWN };

Level getLevel(std::string lvl) {
	if (lvl == "DEBUG") return D;
    if (lvl == "INFO") return I;
    if (lvl == "WARNING") return W;
    if (lvl == "ERROR") return E;
    return UNKNOWN;
}

void Harl::complainFromLevel(std::string level)
{
    switch (getLevel(level)) {
        case D:
            debug();
			// fall through
        case I:
            info();
			// fall through
        case W:
            warning();
			// fall through
        case E:
            error();
            break;
        default:
            std::cout << "\n";
    }
}

Harl::Harl()
{
}

Harl::~Harl()
{
}