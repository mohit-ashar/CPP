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
    try
    {
        if (this->grade < 1)
        {
            this->grade = 150;
	    	throw Bureaucrat::GradeTooHighException();
        }	
        else if (this->grade > 150)
	    {
            this->grade = 150;
            throw Bureaucrat::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::string const   Bureaucrat::getName() const
{
    return (this->name);
}

int                 Bureaucrat::getGrade() const
{
    return (this->grade);
}

void                Bureaucrat::setGrade(int n)
{
    try
	{
		if (n < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (n > 150)
			throw Bureaucrat::GradeTooLowException();
        else
            this->grade = n;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void                Bureaucrat::upgrade( void )
{
    try
    {
        this->setGrade(this->grade - 1);
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void                Bureaucrat::downgrade(void)
{
    try
    {
        this->setGrade(this->grade + 1);
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void                Bureaucrat::signForm(Form f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signs " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " cannot sign " << f.getName() << " because ";
        std::cout << e.what() << std::endl;
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
