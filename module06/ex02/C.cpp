#include "C.hpp"

C::C( void )
{
}

C::~C( void )
{
}

C::C( C const & c)
{
    *this = c;
}

C & C::operator=(C const & c)
{
    (void)c;
    return (*this);
}