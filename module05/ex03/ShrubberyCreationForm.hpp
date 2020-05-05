#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm( void );
    public:
        virtual ~ShrubberyCreationForm( void );
        ShrubberyCreationForm(ShrubberyCreationForm const & scf);
        ShrubberyCreationForm(std::string target);
        virtual void execute(Bureaucrat const & executor) const;
        virtual Form*       clone() const;
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & scf);
        std::string        plantTree() const;
};
std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & scf);
#endif