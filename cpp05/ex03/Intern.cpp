#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

typedef AForm* (*FormCreator)(const std::string &target);

static AForm* makeShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm* makeRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
static AForm* makePardon(const std::string &target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	struct FormPair { std::string name; FormCreator creator; };
	FormPair forms[] = {
		{"shrubbery creation", &makeShrubbery},
		{"robotomy request", &makeRobotomy},
		{"presidential pardon", &makePardon}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cout << "Intern could not find the form: " << formName << std::endl;
	return NULL;
}
