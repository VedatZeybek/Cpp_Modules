#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Vedat");

	a.setGrade(150);
	a.incremetGrade();
	a.decrementGrade();
	a.incremetGrade();
	std::cout << a.getName() << "'s grade is: " << a.getGrade() << "\n";

	std::cout << a;
}