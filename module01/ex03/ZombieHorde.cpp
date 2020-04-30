#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    int i;
    i = 0;
    this->size = n;
    this->z = new Zombie[n];
    while (i < n)
    {
        random_zombie(&this->z[i]);
        i++;
    }
}


ZombieHorde::~ZombieHorde()
{
    delete[] this->z;
    this->z = 0;
}


void    ZombieHorde::random_zombie(Zombie *z)
{
    const std::string names[] = {"Gerrard", "Aguero", "Bernardo", "Suarez", "Fraudiola", "Torres", "Tevez"};
    const std::string types[] = {"scouser", "cheater", "biter", "diver"};
    srand(time(NULL) * rand());
    z->setName(names[rand() % 7]);
    z->setType(types[rand() % 4]);
}

void    ZombieHorde::announce() const
{
    int i = 0;
    while (i < this->size)
    {
        this->z[i].announce();
        i++;
    }
}