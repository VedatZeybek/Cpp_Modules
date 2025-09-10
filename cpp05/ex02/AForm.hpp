#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class AForm
{
private:
	std::string const	name;
	bool				isSigned;
	const int			signRequired;
	const int			execRequired;

public:
	AForm();
	AForm(const AForm& other);
	AForm(const std::string name, int signRequired, int execRequired);
	AForm& operator=(const AForm& other);
	~AForm();

	//You do not have to change but you have to override it
	virtual void execute(Bureaucrat &bureaucrat) const = 0;
    
	
	const std::string getName() const;
	bool getIsSigned() const;
	int getSignRequired() const;
	int getExecRequired() const;
	void setIsSigned(bool isSigned);
	
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

std::ostream &operator<<(std::ostream &os, const AForm &form);


#endif