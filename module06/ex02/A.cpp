#include "A.hpp"

A::A( void )
{
    std::cout << "A generated" << std::endl;
}

A::~A( void )
{
}

A::A( A const & a)
{
    *this = a;
}

A & A::operator=(A const & a)
{
    (void)a;
    return (*this);
}