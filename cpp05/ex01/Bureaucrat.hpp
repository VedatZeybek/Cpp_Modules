#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include "iostream"
#include "Form.hpp"

class Bureaucrat
{
private:
	int			grade;
	std::string	name;

public:
	Bureaucrat();
	Bureaucrat(const std::string name);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void setName(const std::string name);
	std::string getName() const;

	void setGrade(int grade);
	int getGrade() const;

	void incremetGrade();
	void decrementGrade();        
	
	//addition:
	void signForm(Form &form);


	class GradetooHighException : public std::exception 
	{
		public:
			const char * what() const throw();
	};

	class GradetooLowException : public std::exception
	{
		public:
			const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream &ostream, const Bureaucrat &other);


#endif