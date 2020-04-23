#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP
#include <iostream>
#include <stdlib.h>
#include <cerrno>
#include <cstring>
#include <cmath>

class ScalarConversion
{
    private:
        ScalarConversion( void );
    public:
        char        c;
        int         i;
        float       f;
        double      d;
        ScalarConversion( char *str );
        ~ScalarConversion( void );
        ScalarConversion & operator=(ScalarConversion const & sc);
};
#endif