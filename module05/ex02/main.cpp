#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    std::cout << "##############Creating a bureaucrat with copy and assignment##############\n" << std::endl;
    Bureaucrat a("Tyrion Lannister", 60);
    Bureaucrat danny("Danaerys Targaeryn", 1);
    Bureaucrat danny2 = danny;
    Bureaucrat danny3(danny2);
    std::cout << a;
    std::cout << danny;
    std::cout << danny2;
    std::cout << danny3;
    std::cout << "-----------------------" << std::endl;

    std::cout << "##############Creating all three types of forms##############\n" << std::endl;
    ShrubberyCreationForm scf("Winterfell");
    RobotomyRequestForm rmr("Rob");
    RobotomyRequestForm rmr1("Bob");
    RobotomyRequestForm rmr2("Clob");
    RobotomyRequestForm rmr3("Slob");
    RobotomyRequestForm rmr4("Blob");
    PresidentialPardonForm ppf("Cersei");
    std::cout << scf;
    std::cout << rmr;
    std::cout << ppf;
    std::cout << "-----------------------" << std::endl;
    std::cout << "##############Testing sign##############\n" << std::endl;
    a.signForm(scf);
    try
    {
        ppf.beSigned(a); // Trying to sign without proper rank
    }
    catch(std::exception &e)
	{
		std::cout << a.getName() << " cannot sign " << ppf.getName();
		std::cout << " because Bureaucrat grade too low" << std::endl;
	}
    danny.signForm(ppf);
    a.signForm(rmr);
    a.signForm(rmr1);
    a.signForm(rmr2);
    std::cout << "-----------------------" << std::endl;
    std::cout << "##############Testing execution##############\n" << std::endl;
    a.executeForm(scf);
    a.executeForm(rmr);
    danny.executeForm(rmr1);
    danny.executeForm(rmr2);
    a.signForm(rmr3);
    a.signForm(rmr4);
    danny.executeForm(rmr3);
    danny.executeForm(rmr4);
    try
    {
        rmr3.execute(danny);// Trying to execute without sign
    }
    catch(std::exception &e)
	{
		std::cout << danny.getName() << " cannot execute" << ppf.getName();
		std::cout << " because Form not signed" << std::endl;
	}
    try
    {
        a.executeForm(ppf); // Trying to execute without proper grade
    }
    catch(std::exception &e)
	{
		std::cout << a.getName() << " cannot execute" << ppf.getName();
		std::cout << " because Bureaucrat grade too low" << std::endl;
	}
    danny.executeForm(ppf);
}