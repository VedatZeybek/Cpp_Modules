#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) { /* *this = other;*/ }

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		target = other.target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	std::cout << bureaucrat.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

