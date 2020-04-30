#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{

    public:

        Fixed( void );
        Fixed( int const n );
        Fixed( float const n );
        Fixed( Fixed const & src );
        ~Fixed( void );

        Fixed &         operator=(Fixed const & rhs);

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        int     toInt() const;
        float   toFloat() const;
    private:

        int     _n;
        static int const _fract = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);
#endif