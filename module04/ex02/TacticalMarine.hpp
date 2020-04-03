#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
#include "ISpaceMarine.hpp"
#include <iostream>
class TacticalMarine: public ISpaceMarine
{
    public:
        TacticalMarine();
        ~TacticalMarine();
        TacticalMarine(TacticalMarine const & t_marine);
        virtual ISpaceMarine* clone() const;
        virtual void battleCry() const;
        virtual void rangedAttack() const;
        virtual void meleeAttack() const;
        TacticalMarine & operator=(TacticalMarine const & t_marine);
};
#endif

