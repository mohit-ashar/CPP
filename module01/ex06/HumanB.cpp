#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
    this->setName(n);
}

void    HumanB::setName(std::string n)
{
    this->name = n;
}

void    HumanB::setWeapon(Weapon &w1)
{
    this->w = &w1;
}
void    HumanB::attack()
{
    std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}