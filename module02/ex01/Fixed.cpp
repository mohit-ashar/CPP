#include "Fixed.hpp"

Fixed::Fixed( void ): _n( 0 )
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed (int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_n = (n << Fixed::_fract);
    return;
}

Fixed::Fixed (float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_n = roundf(n * (1 << Fixed::_fract));
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_n = rhs.getRawBits();
    return (*this);
}

int     Fixed::getRawBits( void ) const
{
    return (this->_n);
}

void    Fixed::setRawBits( int const raw )
{
    this->_n = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_n / (float)(1 << Fixed::_fract));
}

int Fixed::toInt(void) const
{
	return (this->_n >> Fixed::_fract);
}


std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}