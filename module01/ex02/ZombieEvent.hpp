#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"
# include <iostream>

class ZombieEvent
{
    private:
        std::string type;
    public:
        void    setZombieType(std::string type);
        Zombie* newZombie(std::string name);
};

#endif