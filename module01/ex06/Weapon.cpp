#include "Weapon.hpp"

Weapon::Weapon(std::string w_type)
{
    this->setType(w_type);
}

const std::string&  Weapon::getType() const
{
    return (this->type);
}

void                Weapon::setType(std::string t)
{
    this->type = t;
}
