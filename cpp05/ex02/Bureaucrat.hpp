#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"

class AForm;

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
	void signForm(AForm &form);

    void executeForm(const AForm &form);


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