#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) { /* *this = other;*/ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 25, 5), target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		target = other.target;
		setIsSigned(other.getIsSigned());
	}
	return *this;
}



void ShrubberyCreationForm::execute(Bureaucrat &executor) const
{
    if (!getIsSigned())

    if (executor.getGrade() > getExecRequired())
        throw AForm::GradeTooLowException();

    std::ofstream file((getName() + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Failed to create file!" << std::endl;
        return;
    }

file << "                      &&& &&  & &&\n"
        "                  && &\\/&\\|& ()|/ @, &&\n"
        "                  &\\/(/&/&||/& /_/)_&_&\n"
        "               &() &\\/&|()|/&\\/ '%\" & ()\n"
        "              &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "            &&   && & &| &| /& & % ()& /&&\n"
        "             ()&_---()&\\&\\|&&-&&--%---()~\n"
        "                 &&     \\|||\n"
        "                         |||\n"
        "                         |||\n"
        "                         |||\n"
        "       _62^        , -=-~  .-^- _\n";

    file.close();

    std::cout << "Shrubbery created: " << getName() + "_shrubbery" << std::endl;
}