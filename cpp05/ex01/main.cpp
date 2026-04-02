#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 50);
		Bureaucrat b("Bob", 120);

		Form taxForm("TaxForm", 100, 50);
		Form topSecret("TopSecret", 10, 5);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;

		a.signForm(taxForm);
		b.signForm(taxForm);
		a.signForm(topSecret);

		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	try
	{
		Form wrong("WrongForm", 0, 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Form creation error: " << e.what() << std::endl;
	}

	return 0;
}