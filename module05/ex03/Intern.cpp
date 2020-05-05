#include "Intern.hpp"

Intern::Intern( void )
{
}

Intern::Intern( Intern const & intern )
{
    *this = intern;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & intern)
{
    (void)intern;
    return (*this);
}

Form * Intern::makeForm(std::string formType, std::string target)
{
    int i;
    void *f[3];
    std::string str[3];

    i = 0;
    ShrubberyCreationForm scf("Target");
    RobotomyRequestForm rmr("Rob");
    PresidentialPardonForm ppf("Cersei");
    f[0] = &scf;
    f[1] = &rmr;
    f[2] = &ppf;

    str[0] = "shrubbery creation";
    str[1] = "robotomy request";
    str[2] = "presidential pardon";
    while(i < 3)
    {
        if (str[i] == formType)
        {
            std::cout << "Intern creates a " << static_cast<Form *>(f[i])->getName() << " form!" << std::endl;
            static_cast<Form *>(f[i])->setTarget(target);
            return static_cast<Form *>(f[i])->clone();
        }
        i++;
    }
    std::cout << "Intern is clueless" << std::endl;
    return NULL;
}