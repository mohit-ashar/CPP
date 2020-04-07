#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm( void );
        std::string target;
    public:
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm(ShrubberyCreationForm const & scf);
        ShrubberyCreationForm(std::string target);
        std::string getTarget( void ) const;
        virtual void        setTarget(std::string str);
        virtual Form*       clone() const;
        void execute(Bureaucrat const & executor) const;
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & scf);
        std::string        plantTree() const;
};
std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & scf);
#endif