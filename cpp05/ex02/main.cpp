#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Bureaucrat oluştur
        Bureaucrat alice("Alice", 1); // en yüksek rütbe, her formu çalıştırabilir
        Bureaucrat bob("Bob", 150);   // en düşük rütbe, hiçbir formu çalıştıramaz

        // ShrubberyCreationForm
        ShrubberyCreationForm shrubForm("Home");
        alice.signForm(shrubForm);
        alice.executeForm(shrubForm);

        // RobotomyRequestForm
        RobotomyRequestForm roboForm("Marvin");
        alice.signForm(roboForm);
        alice.executeForm(roboForm);

        // PresidentialPardonForm
        PresidentialPardonForm pardonForm("Trillian");
        alice.signForm(pardonForm);
        alice.executeForm(pardonForm);

        std::cout << "\n--- Copy constructor ve assignment test ---\n";

        // Copy constructor
        ShrubberyCreationForm shrubFormCopy(shrubForm);
        alice.executeForm(shrubFormCopy);

        // Assignment operator
        RobotomyRequestForm roboFormAssign("Dummy");
        roboFormAssign = roboForm;
        alice.executeForm(roboFormAssign);

        // Başarısız durum: düşük rütbeli Bob
        bob.executeForm(pardonForm);

    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
