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
		char        c;
		int         i;
		float       f;
		double      d;
	public:
		int			getI( void );
		float		getF( void );
		double		getD( void );
		char		getC( void );
		ScalarConversion( char *str );
		~ScalarConversion( void );
		ScalarConversion(ScalarConversion const & sc);
		ScalarConversion & operator=(ScalarConversion const & sc);
};
#endif