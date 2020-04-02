#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
    public:
        PlasmaRifle();
        PlasmaRifle(PlasmaRifle & pr);
        ~PlasmaRifle();
        virtual void    attack() const;
        PlasmaRifle & operator=(PlasmaRifle const & pr);
};

#endif