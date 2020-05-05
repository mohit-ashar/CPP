#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
		private:
				std::string const   name;
				bool                is_signed;
				int         const   grade_sign;
				int         const   grade_execute;
				Form( void );
		public:
			~Form( void );
			Form(Form const & f);
			Form(std::string f_name, int f_grade_sign, int f_grade_execute);

			std::string getName() const;
			bool        isSigned() const;
			int         get_grade_sign() const;
			int         get_grade_execute() const;
			void        beSigned(Bureaucrat const b);

			class GradeTooLowException: public std::exception
			{
				virtual const char* what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
				virtual const char* what() const throw();
			};
			
			Form    & operator=(Form const & f);
};

std::ostream & operator<<(std::ostream & o, Form const & b);
#endif