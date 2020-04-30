#include "ZombieEvent.hpp"

void    ZombieEvent::setZombieType(std::string z_type)
{
    this->type = z_type;
}

Zombie*     ZombieEvent::newZombie(std::string z_name)
{
    Zombie *z = new Zombie();
    z->setType(type);
    z->setName(z_name);

    return (z);
}