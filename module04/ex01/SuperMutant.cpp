#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "SuperMutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & sm): Enemy(sm)
{
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void            SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3);
}

SuperMutant & SuperMutant::operator=(SuperMutant const & sm)
{
    if (this != &sm)
    {
        this->enemyType = sm.getType();
        this->hitPoints = sm.getHP();
    }
    return (*this);
}