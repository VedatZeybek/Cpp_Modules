#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signRequired(1), execRequired(1)
{

}

AForm::AForm(const AForm& other) : name("default"), isSigned(false), signRequired(1), execRequired(1)
{
	if (this != &other)
		*this = other;
}

AForm::AForm(const std::string name, int signRequired, int execRequired) :
	name(name), isSigned(false), signRequired(signRequired), execRequired(execRequired)
{
	if (signRequired < 1 || execRequired < 1)
        throw GradeTooHighException();
    if (signRequired > 150 || execRequired > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{

}

void AForm::setIsSigned(bool isSigned) { this->isSigned = isSigned; }
const std::string AForm::getName() const { return (name); }
bool AForm::getIsSigned() const { return (isSigned); }
 int AForm::getSignRequired() const { return (signRequired); }
 int AForm::getExecRequired() const { return (execRequired); }


void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signRequired)
		throw GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream&  operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName()
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Required Sign Grade: " << form.getSignRequired()
	<< ", Required Execute Grade: " << form.getExecRequired();
	
	return (os);
}	   

