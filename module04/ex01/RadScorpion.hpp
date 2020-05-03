#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP
# include "Enemy.hpp"


class RadScorpion: public Enemy
{
    public:
        RadScorpion();
        RadScorpion(RadScorpion const & rs);
        virtual ~RadScorpion();
        RadScorpion & operator=(RadScorpion const & rs);
};

#endif