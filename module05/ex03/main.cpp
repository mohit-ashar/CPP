#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat a("Tyrion Lannister", 20);
    Intern i;

    Form* rrf;
    rrf = i.makeForm("shrubbery creation", "Bender");
    a.signForm(*rrf);
    a.executeForm(*rrf);
    delete rrf;
    std::cout << "-------------------" << std::endl;

    rrf = i.makeForm("robotomy request", "Bender");
    a.signForm(*rrf);
    a.executeForm(*rrf);
    delete rrf;
    std::cout << "-------------------" << std::endl;

    rrf = i.makeForm("presidential pardon", "Bender");
    a.signForm(*rrf);
    a.executeForm(*rrf);
    delete rrf;
    std::cout << "-------------------" << std::endl;
}