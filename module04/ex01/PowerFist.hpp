#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
    public:
        PowerFist();
        PowerFist(PowerFist const & pt);
        ~PowerFist();
        virtual void    attack() const;
        PowerFist & operator=(PowerFist const & pf);
};

#endif