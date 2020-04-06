#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Tyrion Lannister", 1);
    Bureaucrat b(a);
    Form f("Warrant", -22, 2);

    Form copy(f);
    b.signForm(copy);
    Form f1("Warrant 1", 222, 2);
    b.signForm(f1);
    std::cout << "--------\n";

    Form f2("Warrant final", 20, 20);
    b.signForm(f2);
    std::cout << "--------\n";

    Bureaucrat bob("Bob", 49);
    Form will("Will", 10, 2);
    bob.signForm(will);
}