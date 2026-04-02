#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	
	void executeAction() const;
};



#endif