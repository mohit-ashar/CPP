#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde: public Zombie
{
    public:
        int     size;
        ZombieHorde(int n)
        {
            size = n;
        }
        void    announce();
};

#endif