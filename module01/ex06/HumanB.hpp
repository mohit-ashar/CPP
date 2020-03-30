#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *w;
        std::string name;
    public:
        HumanB(std::string n);
        void attack();
        void setName(std::string n);
        void setWeapon(Weapon &w1);
};

#endif