#include "Cure.hpp"
#include "ICharacter.hpp"


Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure contructor called." << std::endl;

}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy contructor called." << std::endl;

	//Cure a;
	//a = a;  // self-assignment
	//Prevent self-assignment // satırında aynı nesneyi kendi üzerine tekrar kopyalamaya çalışırsın.
	//Basit tiplerde sorun olmayabilir ama dynamic memory kullandığında

	if (this != &other)
	{
		    AMateria::operator=(other);
	}
	//*this = other;
	
}

Cure& Cure::operator=(const Cure& other)
{
	type = other.type;
	
	std::cout << "Copy assigment operator is called" << std::endl;
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	return (new Cure(*this));

}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
