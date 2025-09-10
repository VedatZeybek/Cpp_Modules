#ifndef CHARACTER_HPP
#define CHARACTER_HPP

//why ?
//class ICharacter;

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
		AMateria* materia[4]; //you cant gave without pointer
		
public:
	Character();
	Character(const std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();


};



#endif