#include "Base.hpp"

Base::Base( void )
{

}

Base::~Base( void )
{

}

Base::Base(Base const & base)
{
    *this = base;
}

Base & Base::operator=(Base const & base)
{
    (void)base;
    return (*this);
}