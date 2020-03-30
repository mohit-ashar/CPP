#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w1): w(w1)
{
    this->setName(n);
}

void    HumanA::setName(std::string n)
{
    this->name = n;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->w.getType() << std::endl;
}