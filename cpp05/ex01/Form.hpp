#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const	name;
	bool				isSigned;
	const int			signRequired;
	const int			execRequired;

public:
	Form();
	Form(const Form& other);
	Form(const std::string name, int signRequired, int execRequired);
	Form& operator=(const Form& other);
	~Form();

	
	const std::string getName() const;
	bool getIsSigned() const;
	const int getSignRequired() const;
	const int getExecRequired() const;
    void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif