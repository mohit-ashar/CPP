#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "SuperMutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant & sm): Enemy(sm)
{
    *this = sm;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void            SuperMutant::takeDamage(int damage)
{
    if (damage < 0 || damage - 3 < 0)
        return;
    damage = damage - 3;
    if (this->getHP() - damage < 0)
    {
        this->setHP(0);
        return;
    }
    this->setHP(this->getHP() - damage);
}

SuperMutant & SuperMutant::operator = (SuperMutant const & sm)
{
    if (this != &sm)
    {
        this->enemyType = sm.getType();
        this->hitPoints = sm.getHP();
    }
    return (*this);
}