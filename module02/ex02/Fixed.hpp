#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int     _n;
        static int const _fract = 8;
    
    public:

        Fixed( void );
        Fixed( int const n );
        Fixed( float const n );
        Fixed( Fixed const & src );
        ~Fixed( void );

        Fixed &        operator=(Fixed const & rhs);
        
        Fixed          operator+(Fixed const & rhs) const;
        Fixed          operator-(Fixed const & rhs) const;
        Fixed          operator/(Fixed const & rhs) const;
        Fixed          operator*(Fixed const & rhs) const;
        
        static Fixed &       min(Fixed & lhs, Fixed & rhs);
        static Fixed &       max(Fixed & lhs, Fixed & rhs);
        static Fixed const & min(Fixed const & lhs, Fixed const & rhs);
        static Fixed const & max(Fixed const & lhs, Fixed const & rhs);


        Fixed &       operator++(void);
        Fixed         operator++(int);
        Fixed &       operator--(void);
        Fixed         operator--(int);

        bool         operator>(Fixed const & rhs) const;
        bool         operator<(Fixed const & rhs) const;
        bool         operator>=(Fixed const & rhs) const;
        bool         operator<=(Fixed const & rhs) const;
        bool         operator==(Fixed const & rhs) const;
        bool         operator!=(Fixed const & rhs) const;


        int           getRawBits( void ) const;
        int           toInt() const;
        void          setRawBits( int const raw );
        float         toFloat() const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);
Fixed           &min(Fixed & lhs, Fixed & rhs);
Fixed           &max(Fixed & lhs, Fixed & rhs);
Fixed const     &min(Fixed const & lhs, Fixed const & rhs);
Fixed const     &max(Fixed const & lhs, Fixed const & rhs);


#endif