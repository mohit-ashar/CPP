#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string sorcName, std::string sorcTitle)
{
    this->name = sorcName;
    this->title = sorcTitle;
    std::cout << this->name << ", " << this->title << " is born" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer & src)
{
    *this = src;
}

Sorcerer::~Sorcerer( void )
{
    std::cout << this->name << ", " << this->title << "is dead. Consequences will never be the same!" << std::endl;
}

std::string     Sorcerer::getName( void ) const
{
    return (this->name);
}

std::string     Sorcerer::getTitle( void ) const
{
    return (this->title);
}

void            Sorcerer::setName(std::string sorcName)
{
    this->name = sorcName;
}

void            Sorcerer::setTitle(std::string sorcTitle)
{
    this->title = sorcTitle;
}

void            Sorcerer::polymorph(Victim const & vic) const
{
    vic.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const & src)
{
    if (this != &src)
    {
        this->name = src.getName();
        this->title = src.getTitle();
    }
    return (*this);
}

std::ostream & operator << (std::ostream & o, Sorcerer  & src)
{
    o << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies!\n";
    return o;
}