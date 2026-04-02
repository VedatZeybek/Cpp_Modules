#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	
	void executeAction() const;
};




#endif