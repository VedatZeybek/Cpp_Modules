
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat vedat("Vedat", 30);
        Form form("Form", 40, 20);

        std::cout << form << std::endl;
        vedat.signForm(form); 

        Bureaucrat zeybek("Zeybek", 30);
        zeybek.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat vedat("Vedat", 150);
        std::cout << vedat << std::endl;
        vedat.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}