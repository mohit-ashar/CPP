#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    int i;
    i = 0;
    this->size = n;
    this->z = new Zombie[n];
    while (i < n)
    {
        this->z[i].randomChump(&this->z[i]);
        this->z[i].announce();
        i++;
    }
}

ZombieHorde::~ZombieHorde()
{
    delete[] this->z;
    this->z = 0;
}