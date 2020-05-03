#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
    private:
        AWeapon( void );
    protected:
        std::string weaponName;
        int         apCost;
        int         weaponDamage;
    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const & awp);
        virtual ~AWeapon( void );
        std::string const   getName( void ) const;
        int                 getAPCost( void ) const;
        int                 getDamage( void ) const;
        void                setName(std::string name);
        void                setAPCost(int cost);
        void                setWeaponDamage(int damage);
        virtual void        attack( void ) const = 0;
        AWeapon & operator=(AWeapon const & awp);
};

#endif