#include "Fixed.hpp"
int main( void )
{
    Fixed a(10);
    std::cout << a << std::endl;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << ++a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << max( a, b ) << std::endl;
    std::cout << min( a, b ) << std::endl;

    return 0;
}
