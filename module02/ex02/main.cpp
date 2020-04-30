#include "Fixed.hpp"
int main( void )
{
    Fixed a(0);
    std::cout << a << std::endl;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c( Fixed( 10 ) / Fixed( 2 ) );
    Fixed d( Fixed( 10 ) - Fixed( 2 ) );
    Fixed e( Fixed( 10 ) + Fixed( 2 ) );
    std::cout << ++a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << "b:" << b << std::endl;
    std::cout << "c:" << c << std::endl;
    c--;
    std::cout << "c--:" << c << std::endl;
    std::cout << "--c:" << --c << std::endl;
    std::cout << "d:" << d << std::endl;
    std::cout << "e:" << e << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << max( a, b ) << std::endl;
    std::cout << min( a, b ) << std::endl;

    return 0;
}
