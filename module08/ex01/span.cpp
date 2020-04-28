#include "span.hpp"

Span::Span( unsigned int N ):n(N)
{
}

Span::~Span( void )
{
}

Span::Span( Span const & span)
{
    *this = span;
}

Span const & Span::operator=(Span const & span)
{
    this->n = span.n;
    this->lst = span.lst;
    return (*this);
}

void        Span::addNumber(int number)
{
    if (this->lst.size() == (size_t)this->n)
        throw ContainerFullException();
    this->lst.push_back(number);
}

void        Span::addNumber( std::list<int>::iterator begin, std::list<int>::iterator end)
{
    std::list<int>::iterator it;
    for(it = begin; it != end; it++)
    {
        if (this->lst.size() == (size_t)this->n)
            throw ContainerFullException();
        this->lst.push_back(*it);
    }
}

long        Span::shortestSpan( void )
{
    long span = 4294967296;
    long tmp;

    std::list<int>::iterator it;
    std::list<int>::iterator start;
    std::list<int>::iterator end;

    if (this->lst.size() < 2)
        throw NotEnoughNumbersException();
    for (it = this->lst.begin(); it != (this->lst.end()); )
    {
        start = it;
        end = ++it;
        if (end == this->lst.end())
            return (span);
        tmp = std::abs((long)*start - (long)*end);
        if (tmp < span)
            span = tmp;
    }
    return (span);
}

long        Span::longestSpan( void )
{
    long span = 0;
    long tmp = 0;
    std::list<int>::iterator start;
    std::list<int>::iterator end;
    std::list<int>::iterator it;

    if (this->lst.size() < 2)
        throw NotEnoughNumbersException();
    for (it = this->lst.begin(); it != (this->lst.end()); )
    {
        start = it;
        end = ++it;
        if (end == this->lst.end())
            return (span);
        tmp = std::abs((long)*start - (long)*end);
        if (tmp > span)
            span = tmp;
    }
    return (span);
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return ("NotEnoughNumbersException: Not enough numbers to calculate span"); 
}

const char* Span::ContainerFullException::what() const throw()
{
    return ("ContainerFullException: Container is full"); 
}