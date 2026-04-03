#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((target + "_shrubbery.txt").c_str());
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

    std::cout << "Shrubbery created: " << target + "_shrubbery" << std::endl;
}