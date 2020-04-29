#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde: public Zombie
{
    private:
        int     size;
        Zombie  *z;
    public:
        ZombieHorde(int n);
        ~ZombieHorde();
        void    announce();
};

#endif