#include "ZombieHorde.hpp"

void    ZombieHorde::announce()
{
    int i;

    i = 0;
    Zombie *z = new Zombie[size];
    while (i < size)
    {   
        z[i].randomChump();
        i++;
    }
    i = 0;
    delete[] z;
}