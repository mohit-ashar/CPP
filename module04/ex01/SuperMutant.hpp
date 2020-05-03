#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP
# include "Enemy.hpp"

class SuperMutant: public Enemy
{
    public:
        SuperMutant();
        SuperMutant(SuperMutant const & sm);
        virtual ~SuperMutant();
        virtual void    takeDamage(int damage);
        SuperMutant & operator=(SuperMutant const & sm);
};

#endif