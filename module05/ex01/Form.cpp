#include "Form.hpp"

const char*         Form::GradeTooHighException::what() const throw()
{
    return ("Form Exception: Grade too high");   
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return ("Form Exception: Grade too low");   

}

const char*         Form::InvalidFormException::what() const throw()
{
    return ("Form Exception: Invalid form grade");   

}

Form::~Form( void )
{

}

Form::Form(Form const & f):name(f.name),is_signed(f.is_signed), grade_sign(f.grade_sign), grade_execute(f.grade_execute) 
{

}

Form::Form(std::string f_name, int f_grade_sign, int f_grade_execute):name(f_name), is_signed(false), grade_sign(f_grade_sign), grade_execute(f_grade_execute)
{
    try
    {
        if (this->grade_sign < 1 || this ->grade_execute < 1)
        {
	    	throw Form::GradeTooHighException();
        }	
        else if (this->grade_sign > 150 || this->grade_execute > 150)
	    {
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::string            Form::getName() const
{
    return (this->name);
}

bool                   Form::isSigned() const
{
    return (this->is_signed);
}

int                     Form::get_grade_sign() const
{
    return (this->grade_sign);
}

int                     Form::get_grade_execute() const
{
    return (this->grade_execute);
}

void                    Form::beSigned(Bureaucrat const b)
{
    if  (this->get_grade_sign() < 1 || this->get_grade_sign() > 150)
        throw Form::InvalidFormException();
    else if (b.getGrade() <= this->get_grade_sign())
        this->is_signed = true;
    else
        throw Form::GradeTooLowException();    
}