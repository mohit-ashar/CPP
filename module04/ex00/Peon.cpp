#include "Peon.hpp"

Peon::Peon(std::string peon): Victim(peon)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & peon): Victim(peon)
{
}

Peon::~Peon( void )
{
    std::cout << "Bleuark..." << std::endl;
}

void        Peon::getPolymorphed() const
{
    std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}

Peon & Peon::operator = (Peon const & peon)
{
	this->name = peon.name;
	return (*this);
}