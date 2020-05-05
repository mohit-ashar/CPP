#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        PresidentialPardonForm( void );
    public:
        virtual ~PresidentialPardonForm( void );
        PresidentialPardonForm(PresidentialPardonForm const & rmr);
        PresidentialPardonForm(std::string target);
        virtual void        execute(Bureaucrat const & executor) const;
        PresidentialPardonForm &   operator=(PresidentialPardonForm const & rmr);
};
std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & rmr);
#endif