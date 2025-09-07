#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assigment Constructor Called!" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.getIdea(i);
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called!" << std::endl;
}

void Brain::setIdea(const std::string &idea, int index)
{
	if(index>=0 && index<100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if(index>=0 && index<100)
		return (this->ideas[index]);
	return (NULL);
}