#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & rs): Enemy(rs)
{
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rs)
{
    if (this != &rs)
    {
        this->enemyType = rs.getType();
        this->hitPoints = rs.getHP();
    }
    return (*this);
}