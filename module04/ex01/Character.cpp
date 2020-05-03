#include "Character.hpp"

Character::Character(std::string const & name):charName(name), ap(40), awp(NULL)
{
}

Character::Character(Character const & ch):charName(ch.charName), ap(ch.ap), awp(ch.awp)
{
}

Character::~Character()
{
}

int     Character::getAP() const
{
    return (this->ap);
}

void    Character::setAP(int attackPoints)
{
    this->ap = attackPoints;
}

void    Character::recoverAP()
{
    if ( this->getAP() > 30)
    {
        this->setAP(40);
        return ;
    }
    this->setAP(this->getAP() + 10);
}

void    Character::equip(AWeapon* awpn)
{
    if (awpn == NULL)
        return ;
    std::cout << this->charName << " has equipped " << awpn->getName() << std::endl;
    this->awp = awpn;
}

void    Character::attack(Enemy* enemy)
{
    if (this->awp == 0)
    {
        std::cout << this->charName << " is unarmed" << std::endl;
        return;
    }
    if (!enemy || this->ap < awp->getAPCost())
        return;
    std::cout << this->charName << " attacks " << enemy->getType();
    std::cout << " with a " << awp->getName() << std::endl;
    awp->attack();
    enemy->takeDamage(awp->getDamage());
    this->ap = this->ap - awp->getAPCost();
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::string const   Character::getName() const
{
    return (this->charName);
}

AWeapon*    Character::getAWP() const
{
    return (this->awp);
}

Character &Character::operator=(Character const &ch)
{
	this->charName = ch.getName();
	return (*this);
}

std::ostream & operator << (std::ostream & o, Character  & ch)
{
    if (ch.getAWP() == 0)
        o << ch.getName() << " has " << ch.getAP() << " AP and is unarmed." << std::endl;
    else
        o << ch.getName() << " has " << ch.getAP() << " AP and wields a " << ch.getAWP()->getName() << std::endl;
    return o;
}