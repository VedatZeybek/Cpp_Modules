#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"

class Zombie
{

private:
	std::string name;

public:
	void		announce(void); 
	void		setName(std::string name);
	std::string getName() const;
	Zombie(std::string name);
	std::string name1;
	~Zombie();
	
};

void		randomChump( std::string name);
Zombie*		newZombie(std::string name);

#endif