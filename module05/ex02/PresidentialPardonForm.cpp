#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rmr):Form(rmr)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string tgt):Form("PresidentialPardonForm", 25, 5, tgt)
{
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << this->getTarget() <<" has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & scf)
{
    this->Form::setTarget(scf.Form::getTarget());
    return (*this);
}


std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & scf)
{
    o << scf.getName() << ", sign grade " << scf.get_grade_sign() << std::endl;
    return o;
}