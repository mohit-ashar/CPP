#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & pr): AWeapon(pr)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void        PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & pr)
{
    if (this != &pr)
    {
        this->weaponName = pr.getName();
        this->weaponDamage = pr.getDamage();
        this->apCost = pr.getAPCost();
    }
    return (*this);
}
