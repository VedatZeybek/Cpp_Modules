#include "PresidentialPardonForm.hpp"


#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

