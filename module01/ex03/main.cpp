#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    ZombieHorde *z1 = new ZombieHorde(15);
    delete z1;
    z1 = 0;
}