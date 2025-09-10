#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
}	

AMateria::~AMateria()
{

}
AMateria::AMateria(std::string const& type)
{
	this->type = type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}



std::string const & AMateria::getType() const
{
	return (type);
}
