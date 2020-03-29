#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    ZombieHorde *z1 = new ZombieHorde(15);
    z1->announce();
    delete z1;
}