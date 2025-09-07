#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"

class Animal
{
protected:
	std::string name;
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};


#endif