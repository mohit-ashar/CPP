# include "Zombie.hpp"
# include "ZombieEvent.hpp"

int main()
{
    Zombie z;
    Zombie random_z;
    Zombie *z1;
    ZombieEvent ze;

    z.setName("Zee 1");
    z.setType("Zuzu");
    z.announce();
    z.randomChump();
    ze.setZombieType("Psycho");
    z1 = ze.newZombie("Zomboi");
    z1->announce();
    delete z1;
    z1 = 0;
    return (0);
}