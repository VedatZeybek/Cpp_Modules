#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*funcs[3])(const std::string&) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Intern couldn't create form because form name is invalid" << std::endl;
	return NULL;
}
