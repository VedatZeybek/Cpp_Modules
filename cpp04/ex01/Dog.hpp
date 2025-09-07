#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{	
public:
	Dog();
	Dog(const std::string& type);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	Brain* getBrain() const;
	void makeSound() const;
private:
	Brain *brain;
};


#endif