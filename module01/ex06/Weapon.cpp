#include "Weapon.hpp"

Weapon::Weapon(std::string w_type)
{
    this->setType(w_type);
}

const std::string&  Weapon::getType()
{
    std::string& ref = this->type;
    return (ref);
}

void                Weapon::setType(std::string t)
{
    this->type = t;
}
