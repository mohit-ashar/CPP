#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>

class Span
{
    private:
        int n;
        std::list<int> lst;
        Span( void );
    public:
        Span( unsigned int N );
        ~Span( void );
        Span( Span const & span );
        void addNumber( int number );
        void addNumber( std::list<int>::iterator begin, std::list<int>::iterator end );
        long  shortestSpan( void );
        long  longestSpan( void );
        Span const & operator=(Span const & span);
        class NotEnoughNumbersException: public std::exception
        {
            const char* what() const throw();
        };
        class ContainerFullException: public std::exception
        {
            const char* what() const throw();
        };
};
#endif