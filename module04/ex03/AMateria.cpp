#include "AMateria.hpp"

AMateria::AMateria(): _xp(0), materiaType(0)
{

}

AMateria::AMateria(std::string const & type)
{
    this->materiaType = type;
    this->_xp = 0;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &am)
{
    this->materiaType = am.materiaType;
    this->_xp = am._xp;
}

std::string const &AMateria::getType() const
{
    return (this->materiaType);
}

void                AMateria::setType(std::string type)
{
    this->materiaType = type;
}

unsigned int AMateria::getXP() const
{
    return (this->_xp);
}

void                AMateria::setXP(unsigned int xp)
{
    this->_xp = xp;
}

void        AMateria::use(ICharacter &target)
{
    (void)target;
    this->_xp = this->_xp + 10;
}

AMateria &AMateria::operator=(AMateria const &am)
{
    if (this != &am)
    {
         this->materiaType = am.materiaType;
         this->_xp = am._xp;
    }
    return (*this);
}