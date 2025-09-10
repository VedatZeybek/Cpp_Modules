#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signRequired(1), execRequired(1)
{

}

Form::Form(const Form& other) : name("default"), isSigned(false), signRequired(1), execRequired(1)
{
	if (this != &other)
		*this = other;
}

Form::Form(const std::string name, int signRequired, int execRequired) :
	name(name), isSigned(false), signRequired(signRequired), execRequired(execRequired)
{
	if (signRequired < 1 || execRequired < 1)
        throw GradeTooHighException();
    if (signRequired > 150 || execRequired > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{

}

const std::string Form::getName() const { return (name); }
bool Form::getIsSigned() const { return (isSigned); }
const int Form::getSignRequired() const { return (signRequired); }
const int Form::getExecRequired() const { return (execRequired); }


void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signRequired)
		throw GradeTooLowException();
	isSigned = true;
}


std::ostream&  operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << form.getSignRequired()
       << ", Required Execute Grade: " << form.getExecRequired();
}
