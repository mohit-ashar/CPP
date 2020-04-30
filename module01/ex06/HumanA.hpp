#ifndef HUMANA_HPP
#define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"
class HumanA
{
    private:
        Weapon &w;
        std::string name;
    public:
        HumanA(std::string n, Weapon &w1);
        void    attack();
        void    setName(std::string n);
};

#endif