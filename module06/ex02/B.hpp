#ifndef B_HPP
# define B_HPP
# include "Base.hpp"

class B: public Base
{
    public:
        B( void );
        B( B const & b); 
        virtual ~B();
        B & operator=(B const & b);
};
#endif