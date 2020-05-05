#include "B.hpp"

B::B( void )
{
    std::cout << "B generated" << std::endl;
}

B::~B( void )
{
}

B::B( B const & b)
{
    *this = b;
}

B & B::operator=(B const & b)
{
    (void)b;
    return (*this);
}