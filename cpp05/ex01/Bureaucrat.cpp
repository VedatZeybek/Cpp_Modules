#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Bureaucrat")
{
	std::cout << "Default Constructor is called" << std::endl;
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(150)
{
	std::cout << "Parametized Constructor(name) is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy Constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	std::cout << "Parametized Constructor(name, grade) is called" << std::endl;
	setGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		setGrade(other.grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destrcutor is called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade >= 1 && grade <= 150)
		this->grade  = (grade);
	else if (grade > 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();	
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	setGrade(grade - 1);
	std::cout   << "Grade increment is succesful. New Grade is: "
				<< getGrade() << std::endl; 
}

void Bureaucrat::decrementGrade()
{
	setGrade(grade + 1);
	std::cout   << "Grade decrement is succesful. New Grade is: "
				<< getGrade() << std::endl; 
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High!!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low!!!");
}


std::ostream& operator<<(std::ostream &ostream, const Bureaucrat &other)
{
	ostream << other.getName()  << ", bureaucrat grade: " << other.getGrade() << std::endl;

	return (ostream);
}


void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name << " couldn’t sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}