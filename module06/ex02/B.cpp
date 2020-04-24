#include "B.hpp"

B::B( void )
{
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