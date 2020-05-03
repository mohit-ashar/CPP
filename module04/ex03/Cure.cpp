# include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(Cure const &cure): AMateria(cure)
{
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void        Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    AMateria::use(target);
}

Cure & Cure::operator=(Cure const & cure)
{
    std::string type(cure.getType());
    this->setXP(cure.getXP());
    this->materiaType = type;
    return (*this);
}