#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        RobotomyRequestForm( void );
        std::string target;
    public:
        ~RobotomyRequestForm( void );
        RobotomyRequestForm(RobotomyRequestForm const & rmr);
        RobotomyRequestForm(std::string target);
        std::string getTarget( void ) const;
        void        execute(Bureaucrat const & executor) const;
        RobotomyRequestForm &   operator=(RobotomyRequestForm const & rmr);
};
std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rmr);
#endif