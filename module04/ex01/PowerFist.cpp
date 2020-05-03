#include "PowerFist.hpp"

PowerFist::PowerFist():AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const & pf): AWeapon(pf)
{
}

PowerFist::~PowerFist()
{
}

void        PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & pf)
{
    if (this != &pf)
    {
        this->weaponName = pf.getName();
        this->weaponDamage = pf.getDamage();
        this->apCost = pf.getAPCost();
    }
    return (*this);

}
