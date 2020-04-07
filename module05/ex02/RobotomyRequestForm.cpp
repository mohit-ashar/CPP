#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void )
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rmr):Form(rmr)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string tgt):Form("RobotomyRequestForm", 72, 45)
{
    this->target = tgt;
}

std::string RobotomyRequestForm::getTarget( void ) const
{
    return (this->target);
}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int count;

    Form::execute(executor);
    count++;
    std::cout << "***LOUD DRILLING NOISES***" << std::endl;
    if (count % 2)
        std::cout << this->getTarget() << " has been robotomized succesffully" << std::endl;
    else
        std::cout << "Failed to robotomize " << this->getTarget() << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & scf)
{
    std::string tgt(scf.getTarget());
    this->target = tgt;
    return (*this);
}


std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & scf)
{
    o << scf.getName() << ", sign grade " << scf.get_grade_sign() << std::endl;
    return o;
}