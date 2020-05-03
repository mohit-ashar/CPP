#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
    this->weaponName = name;
    this->apCost = apcost;
    this->weaponDamage = damage;
}

AWeapon::AWeapon(AWeapon const & awp)
{
    *this = awp;
}

AWeapon::~AWeapon( void )
{
}

std::string const   AWeapon::getName( void ) const
{
    return (this->weaponName);
}

int     AWeapon::getAPCost( void ) const
{
    return (this->apCost);
}

int     AWeapon::getDamage( void ) const
{
    return (this->weaponDamage);
}

void    AWeapon::setName(std::string name)
{
    this->weaponName = name;
}

void    AWeapon::setAPCost(int cost)
{
    this->apCost = cost;
}

void    AWeapon::setWeaponDamage(int damage)
{
    this->weaponDamage = damage;
}

AWeapon & AWeapon::operator=(AWeapon const & awp)
{
    if (this != &awp)
    {
        this->weaponName = awp.getName();
        this->weaponDamage = awp.getDamage();
        this->apCost = awp.getAPCost();
    }
    return (*this);
}