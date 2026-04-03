#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Bureaucrat boss("Vito Corleone", 1);
	Bureaucrat mid("Enver Yucel", 70);
	Bureaucrat low("Huseyin Yucel", 150);

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("ARIFv216");
	PresidentialPardonForm pardon("Trump Form");

	low.signForm(shrub);
	mid.signForm(shrub);
	mid.executeForm(shrub);

	mid.signForm(robot);
	mid.executeForm(robot);
	boss.executeForm(robot);

	boss.signForm(pardon);
	boss.executeForm(pardon);

	return 0;
}