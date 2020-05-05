#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const  name;
        int                grade;
        Bureaucrat( void );
    public:
        ~Bureaucrat( void );
        Bureaucrat(Bureaucrat const & b);
        Bureaucrat(std::string b_name, int b_grade);
        
        std::string const getName() const;
        int               getGrade() const;
        
        void              upgrade( void );
        void              downgrade( void );
        
        void              signForm(Form &f);
        void              executeForm(Form const & form);
        class GradeTooLowException: public std::exception
        {
          virtual const char* what() const throw();
        };

        class GradeTooHighException: public std::exception
        {
          virtual const char* what() const throw();
        };

        Bureaucrat & operator=(Bureaucrat const & b);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);
#endif