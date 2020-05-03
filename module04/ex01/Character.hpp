#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    private:
        Character();
        std::string charName;
        int         ap;
        AWeapon*    awp;
    public:
        Character(std::string const & name);
        Character(Character const & ch);
        ~Character();

        int                 getAP() const;
        void                setAP(int attackPoints);
        void                recoverAP();
        AWeapon*            getAWP() const;
        void                equip(AWeapon* awpn);
        void                attack(Enemy* enemy);
        std::string const   getName() const;
        Character &         operator=(Character const &ch);

};

std::ostream & operator << (std::ostream & o, Character  & ch);

#endif