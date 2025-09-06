#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(const std::string& type);
	Cat(Cat &other);
	Cat &operator=(Cat &other);
	~Cat();
};


#endif