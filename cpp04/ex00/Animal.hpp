#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"

class Animal
{
protected:
	std::string name;
public:
	Animal();
	Animal(const std::string& type);
	Animal(Animal &other);
	Animal &operator=(Animal &other);
	virtual ~Animal();

	void makeSound();
};




#endif