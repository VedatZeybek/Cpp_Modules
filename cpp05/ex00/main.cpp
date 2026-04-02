#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Vedat");

	a.setGrade(12);
	try
	{
		a.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; 
		return (1);
	}
	a.setGrade(110);
	try
	{
		a.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; 
		return (1);
	}
	std::cout << a.getName() << "'s grade is: " << a.getGrade() << "\n";
	std::cout << a;
}
