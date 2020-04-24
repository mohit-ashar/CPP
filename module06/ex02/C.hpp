#ifndef C_HPP
# define C_HPP
# include "Base.hpp"
class C: public Base
{
    public:
        C( void );
        C( C const & c); 
        virtual ~C();
        C & operator=(C const & c);
};
#endif