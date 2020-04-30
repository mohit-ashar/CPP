#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
    private:
        int     size;
        Zombie  *z;
        void    random_zombie(Zombie *z);
    public:
        ZombieHorde(int n);
        ~ZombieHorde();
        void    announce() const;
};

#endif