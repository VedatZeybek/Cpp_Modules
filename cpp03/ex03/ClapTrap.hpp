#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "iostream"

class ClapTrap
{
protected:
	std::string name;
	int	health;
	int energy;
	int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();

	void printStatus() const;
	
	// Getters
    std::string getName() const;
    int getHealth() const;
    int getEnergy() const;
    int getAttackDamage() const;
    // Setters
    void setName(const std::string& newName);
    void setHealth(int newHealth);
    void setEnergy(int newEnergy);
    void setAttackDamage(int newAttackDamage);
};



#endif