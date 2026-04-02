#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 70);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

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