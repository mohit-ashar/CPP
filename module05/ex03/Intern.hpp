#ifndef INTERN_HPP
# define INTERN_HPP
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:

    public:
        Intern( void );
        Intern( Intern const & intern);
        ~Intern( void );
        Intern & operator=(Intern const & intern);
        Form * makeForm(std::string formType, std::string target);
};

#endif