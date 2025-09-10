#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) { /* *this = other;*/ }

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 25, 5), target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		target = other.target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat &executor) const
{
    if (!getIsSigned())
        std::cerr << "Did not signed" << std::endl;
    if (executor.getGrade() > getExecRequired())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises... Bzzzzzz!" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << getName() << std::endl;
}

