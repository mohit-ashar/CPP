#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP
# include "Enemy.hpp"


class RadScorpion: public Enemy
{
    public:
        RadScorpion();
        RadScorpion(RadScorpion & rs);
        ~RadScorpion();
        RadScorpion & operator=(RadScorpion const & rs);
};

#endif