#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <ctime>

class Zombie
{
    private:
        std::string name;
        std::string type;
    public:
        void    announce();
        void    setName(std::string z_name);
        void    setType(std::string z_type);
        void    randomChump(Zombie *z);
};

#endif