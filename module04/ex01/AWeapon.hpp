#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
    protected:
        AWeapon( void );
        std::string weaponName;
        int         apCost;
        int         weaponDamage;
    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon & awp);
        ~AWeapon();
        std::string const   getName() const;
        void                setName(std::string const & name);
        int                 getAPCost() const;
        void                setAPCost(int apcost);
        int                 getDamage() const;
        void                setDamage(int damage);
        virtual void        attack() const = 0;
        AWeapon & operator=(AWeapon const & awp);
};

#endif