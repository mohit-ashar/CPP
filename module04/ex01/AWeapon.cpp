#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
    this->weaponName = name;
    this->apCost = apcost;
    this->weaponDamage = damage;
}

AWeapon::AWeapon(AWeapon & awp)
{
    *this = awp;
}

AWeapon::~AWeapon()
{
}

std::string const   AWeapon::getName() const
{
    return (this->weaponName);
}

void     AWeapon::setName(std::string const & name)
{
    this->weaponName = name;
}

int     AWeapon::getAPCost() const
{
    return (this->apCost);
}

void    AWeapon::setAPCost(int apcost)
{
    this->apCost = apcost;
}

int     AWeapon::getDamage() const
{
    return (this->weaponDamage);
}

void    AWeapon::setDamage(int damage)
{
    this->weaponDamage = damage;
}

AWeapon & AWeapon::operator = (AWeapon const & awp)
{
    if (this != &awp)
    {
        this->weaponName = awp.getName();
        this->weaponDamage = awp.getDamage();
        this->apCost = awp.getAPCost();
    }
    return (*this);
}