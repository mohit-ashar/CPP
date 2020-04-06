#include "Victim.hpp"

Victim::Victim(std::string vicName)
{
    this->name = vicName;
    std::cout << "Some random victim named " << this->name << " just appeared." << std::endl;
}

Victim::Victim(Victim & vic)
{
    *this = vic;
}

Victim::~Victim( void )
{
    std::cout << "Victim " << this->name << " died for no apparent reason!" << std::endl;
}

std::string     Victim::getName( void ) const
{
    return (this->name);
}

void            Victim::setName(std::string vicName)
{
    this->name = vicName;
}

Victim & Victim::operator=(Victim const & vic)
{
    if (this != &vic)
        this->name = vic.getName();
    return (*this);
}

void            Victim::getPolymorphed( void ) const
{
    std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream & operator << (std::ostream & o, Victim  & vic)
{
    o << "I am " << vic.getName() << " and I like otters!\n";
    return o;
}