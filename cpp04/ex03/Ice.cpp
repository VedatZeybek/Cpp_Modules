#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice contructor called." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	//*this = other;

	std::cout << "Ice copy contructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	type = other.type;
	
	std::cout << "Copy assigment operator is called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


Ice::~Ice()
{

}
