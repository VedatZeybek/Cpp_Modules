#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat alice("Alice", 1);
	AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (form1)
	{
		alice.signForm(*form1);
		alice.executeForm(*form1);
		delete form1;
	}
	AForm* form2 = someRandomIntern.makeForm("robotomy request", "Marvin");
	if (form2)
	{
		alice.signForm(*form2);
		alice.executeForm(*form2);
		delete form2;
	}
	AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Trillian");
	if (form3)
	{
		alice.signForm(*form3);
		alice.executeForm(*form3);
		delete form3;
	}
	AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody");
	if (form4) delete form4;
	return 0;
}
