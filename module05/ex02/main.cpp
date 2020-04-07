#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    Bureaucrat a("Tyrion Lannister", 60);
    ShrubberyCreationForm scf("Target");
    RobotomyRequestForm rmr("Rob");
    PresidentialPardonForm ppf("Cersei");
    std::cout << scf;
    a.signForm(scf);
    a.signForm(ppf);
    a.signForm(rmr);
    a.executeForm(scf);
    a.executeForm(rmr);
    a.executeForm(rmr);
    a.executeForm(rmr);
    a.executeForm(rmr);
    a.executeForm(ppf);
}