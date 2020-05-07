#include <iostream>

template <typename T>
T  &max (T &x, T &y)
{
    return (x > y ? x : y);
}

template <typename T>
T  &min (T &x, T &y)
{
    return (x < y ? x : y);
}

template <typename T>
void    swap(T &x, T &y)
{
    T tmp(x);
    x = y;
    y = tmp;
}

int main( void )
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
    std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
    std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
    float e = 4.2;
    float f = 4.3;
    ::swap( e, f );
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min( e, f ) << std::endl;
    std::cout << "max(e, f) = " << ::max( e, f ) << std::endl;
    double g = 10008;
    double h = 10008.5;
    ::swap( g, h );
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min( g, h ) << std::endl;
    std::cout << "max(g, h) = " << ::max( g, h ) << std::endl;
    char i = 'a';
    char j = 'A';
    ::swap( i, j );
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min(i, j) = " << ::min( i, j ) << std::endl;
    std::cout << "max(i, j) = " << ::max( i, j ) << std::endl;
    
    return 0;
}