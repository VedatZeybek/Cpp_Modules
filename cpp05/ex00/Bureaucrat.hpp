#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include "iostream"

class Bureaucrat
{
	//order is matter  //const must be initialized first
	private:
	const std::string	name;
	int			grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void setName(const std::string name);
	std::string getName() const;

	void setGrade(int grade);
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception 
	{
		public:
			const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream &ostream, const Bureaucrat &other);


#endif
