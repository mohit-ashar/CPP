#include "Bureaucrat.hpp"

const char*     Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Exception: Grade too high");
}

const char*     Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Exception: Grade too low");
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & b):name(b.name), grade(b.grade)
{
    *this = b;
}

Bureaucrat::Bureaucrat(std::string b_name, int b_grade):name(b_name), grade(b_grade)
{
    if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string const   Bureaucrat::getName() const
{
    return (this->name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->grade);
}

void                Bureaucrat::upgrade( void )
{
    if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void                Bureaucrat::downgrade(void)
{
    if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void                Bureaucrat::signForm(Form &f)
{
    if (f.get_grade_sign() < this->grade)
	{
		std::cerr << this->name << " cannot sign " << f.getName()
		<< " because Bureaucrat grade too low" << std::endl;
	}
	else if (f.isSigned())
	{
		std::cerr << this->name << " cannot sign " << f.getName()
				  << " because Form is already signed" << std::endl;
	}
	else
	{
		f.beSigned(*this);
		std::cout << this->name << " signs " << f.getName() << std::endl;
	}
}

Bureaucrat &    Bureaucrat::operator=(Bureaucrat const & b)
{
    this->grade = b.grade;
    return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return o;
}
