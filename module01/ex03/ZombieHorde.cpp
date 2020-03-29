#include "ZombieHorde.hpp"

void    ZombieHorde::announce()
{
    int i;

    i = 0;
    Zombie *z[size];
    while (i < size)
    {   
        z[i] = new Zombie();
        z[i]->randomChump();
        i++;
    }
    i = 0;
    while (i < size)
    {
        delete z[i];
        i++;
    }
}