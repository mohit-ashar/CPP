#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rmr):Form(rmr)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string tgt):Form("PresidentialPardonForm", 25, 5)
{
    this->target = tgt;
}

std::string PresidentialPardonForm::getTarget( void ) const
{
    return (this->target);
}

void        PresidentialPardonForm::setTarget( std::string str)
{
    this->target = str;
}

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << this->getTarget() <<" has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & scf)
{
    std::string tgt(scf.getTarget());
    this->target = tgt;
    return (*this);
}

Form*       PresidentialPardonForm::clone () const
{
    PresidentialPardonForm *f = new PresidentialPardonForm(*this);
    f->target = this->target;
    return (f);
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & scf)
{
    o << scf.getName() << ", sign grade " << scf.get_grade_sign() << std::endl;
    return o;
}