#include "Form.hpp"

const char*         Form::GradeTooHighException::what() const throw()
{
    return ("Form Exception: Grade too high");   
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return ("Form Exception: Grade too low");   

}

Form::~Form( void )
{

}

Form::Form(Form const & f):name(f.name),is_signed(f.is_signed), grade_sign(f.grade_sign), grade_execute(f.grade_execute) 
{

}

Form::Form(std::string f_name, int f_grade_sign, int f_grade_execute):name(f_name), is_signed(false), grade_sign(f_grade_sign), grade_execute(f_grade_execute)
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

    if (b.getGrade() <= this->get_grade_sign())
        this->is_signed = true;
    else
        throw Form::GradeTooLowException();    
}

Form &Form::operator=(Form const &f)
{
    this->is_signed = f.is_signed;
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Form const & f)
{
    o << "Form name: " << f.getName() << "\nForm sign status: " << f.isSigned();
    o <<"\nForm sign grade: " << f.get_grade_sign() <<"\nForm execute grade "<< f.get_grade_execute() << std::endl;
    return o;
}