#ifndef HUMANB_HPP
#define HUMANB_HPP


#include "iostream"
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*weapon;
	
public:
	std::string	name;
	void		attack();
	void		setWeapon(Weapon& weapon);
	HumanB(std::string name);
	~HumanB();
};





#endif