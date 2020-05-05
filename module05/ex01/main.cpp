#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Tyrion Lannister", 14);
    Bureaucrat t("Tywin Lannister", 1);

    Bureaucrat b(a);
    Form f("Warrant", 12, 2);
    std::cout << f;

    std::cout << "----------Assignation case-----------" <<std::endl;
    Form f11 = f;
    t.signForm(f11);
    a.signForm(f11);

    std::cout << "----------Copy constructor case success-----------" <<std::endl;
    Form f2("Warrant final", 20, 20);
    try
    {
        f2.beSigned(b);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------Incorrect form cases-----------" <<std::endl;
    try
    {
        Form f0("Warrant 0", -1, 2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form f0("Warrant 0", 151, 2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f0("Warrant 0", 1, -1);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form f0("Warrant 0", 10, 152);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------Bureaucrat grade too low to sign-----------" <<std::endl;
    Form f1("Warrant 1", 1, 2);
    try
    {
        f1.beSigned(b);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------Check if form is already signed-----------" <<std::endl;
    Bureaucrat bob("Bob", 49);
    Bureaucrat bob1("Bob1", 4);
    Form will("Will", 10, 2);
    try
    {
        bob.signForm(will);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        bob1.signForm(will);
        bob1.signForm(will);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}