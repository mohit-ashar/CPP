#include "Fixed.hpp"

Fixed::Fixed( void ): _n( 0 )
{
    return;
}

Fixed::Fixed (int const n)
{
    this->_n = (n << Fixed::_fract);
    return;
}

Fixed::Fixed (float const n)
{
    this->_n = roundf(n * (1 << Fixed::_fract));
    return;
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
    return;
}

Fixed::~Fixed( void )
{
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    this->_n = rhs.getRawBits();
    return (*this);
}

Fixed  Fixed::operator+(Fixed const & rhs) const
{
    Fixed tmp = Fixed();
    tmp.setRawBits(this->_n + rhs.getRawBits());
    return (tmp);
}

Fixed  Fixed::operator-(Fixed const & rhs) const
{
    Fixed tmp = Fixed();
    tmp.setRawBits(this->_n - rhs.getRawBits());
    return (tmp);
}

Fixed  Fixed::operator/(Fixed const & rhs) const
{
    Fixed tmp = Fixed();
    tmp.setRawBits(this->_n * (1<<Fixed::_fract) / rhs.getRawBits());
    return (tmp);
}

Fixed  Fixed::operator*(Fixed const & rhs) const
{
    Fixed tmp = Fixed();
    tmp.setRawBits((this->_n * rhs.getRawBits()) / (1 << Fixed::_fract));
    return (tmp);
}

bool    Fixed::operator>(Fixed const & rhs) const
{
    return (this->_n > rhs.getRawBits());
}

bool    Fixed::operator<(Fixed const & rhs) const
{
    return (this->_n < rhs.getRawBits());
}

bool    Fixed::operator<=(Fixed const & rhs) const
{
    return (this->_n <= rhs.getRawBits());
}

bool    Fixed::operator>=(Fixed const & rhs) const
{
    return (this->_n >= rhs.getRawBits());
}

bool    Fixed::operator==(Fixed const & rhs) const
{
    return (this->_n == rhs.getRawBits());
}

bool    Fixed::operator!=(Fixed const & rhs) const
{
    return (this->_n != rhs.getRawBits());
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

Fixed &         Fixed::operator++(void)
{
    this->_n++;
    return (*this);
}

Fixed           Fixed::operator++(int)
{
        Fixed tmp = Fixed(*this);
        ++*this;
        return (tmp);
}

Fixed &         Fixed::operator--(void)
{
    this->_n--;
    return (*this);
}

Fixed           Fixed::operator--(int)
{
        Fixed tmp(*this);
        operator--();
        return (tmp);
}

Fixed &         Fixed::min(Fixed & lhs, Fixed & rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed const  &   Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed &         Fixed::max(Fixed & lhs, Fixed & rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

Fixed const  &   Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

Fixed     &min(Fixed & lhs, Fixed & rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed const          &min(Fixed const & lhs, Fixed const & rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}


Fixed     &max(Fixed & lhs, Fixed & rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

Fixed const          &max(Fixed const & lhs, Fixed const & rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}