#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde: public Zombie
{
    public:
        int     size;
        Zombie  *z;
        ZombieHorde(int n);
        ~ZombieHorde();
        void    announce();
};

#endif