#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default Constructor is called" << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(const std::string name)
{
	std::cout << "Parametized Constructor(name) is called" << std::endl;
	setName(name);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Copy Constructor is called" << std::endl;

	if (this != &other)
		*this = other;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	std::cout << "Parametized Constructor(name, grade) is called" << std::endl;
	setName(name);
	setGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		setGrade(other.grade);
		setName(other.name);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destrcutor is called" << std::endl;
}

void Bureaucrat::setName(const std::string name)
{
	this->name = name;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade >= 0 && grade <= 150)
		this->grade  = (grade);
	else if (grade > 150)
		throw GradetooHighException();
	else
		throw GradetooLowException();	
}

int Bureaucrat::getGrade() const
{
	return (grade);
}


void Bureaucrat::incremetGrade()
{
	try
	{
		setGrade(grade + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout   << "Grade increment is succesful. New Grade is: "
				<< getGrade() << std::endl; 
}

void Bureaucrat::decrementGrade()
{
	try
	{
		setGrade(grade - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; 
		return ;
	}
	std::cout   << "Grade decrement is succesful. New Grade is: "
				<< getGrade() << std::endl; 
}

const char *Bureaucrat::GradetooHighException::what() const throw()
{
	return ("Grade too High!!!");
}

const char *Bureaucrat::GradetooLowException::what() const throw()
{
	return ("Grade too Low!!!");
}


std::ostream& operator<<(std::ostream &ostream, const Bureaucrat &other)
{
	ostream << other.getName()  << ", bureaucrat grade: " << other.getGrade() << std::endl;

	return (ostream);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " 
				<< form.getName() << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " 
				<< form.getName() << " because " << e.what() << std::endl;
	}
}
