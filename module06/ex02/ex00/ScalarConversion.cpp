#include  "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(char *str)
{
	errno = 0;
	if (strlen(str) == 1 && !isdigit(str[0]))
		this->d = static_cast<int>(str[0]);
	else
		this->d = strtod(str, NULL);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (strlen(str) == 1 && !isdigit(str[0]))
		this->f = static_cast<int>(str[0]);
	else
		this->f = strtof(str, NULL);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: "<< this->d; 
		if (this->d - floor(this->d) == 0 && this->d < static_cast<double>(1000000) && this->f > static_cast<double>(-1000000))
			std::cout << ".0";
		std::cout << std::endl;
		return ;
	}
	long l;
	if (strlen(str) == 1 && !isdigit(str[0]))
		this->i = static_cast<int>(str[0]);
	else
		l = strtol(str, NULL, 10);
	if (errno == ERANGE || l > 2147483647 || l < static_cast<long>(-2147483648)\
	|| !strcmp(str, "-inf") || !strcmp(str, "-inff")\
	|| !strcmp(str, "+inf") || !strcmp(str, "+inff")\
	|| !strcmp(str, "nan") || !strcmp(str, "nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		this->i = static_cast<int>(this->f);
		if ( this->i < 32 || this->i > 126)
			std::cout << "char: Not Displayable" << std::endl;
		else
		{
			this->c = static_cast<char>(this->i);
			std::cout << "char: " << this->c << std::endl;
		}
		std::cout << "int: " << this->i << std::endl;
	}
	std::cout << "float: " << this->f;
	if (this->f - floor(this->f) == 0 && this->f < static_cast<float>(1000000) && this->f > static_cast<float>(-1000000))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << this->d;
	if (this->d - floor(this->d) == 0 && this->d < static_cast<float>(1000000) && this->f > static_cast<double>(-1000000))
		std::cout << ".0";
	std::cout << std::endl;
}

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &sc)
{
	this->c = sc.c;
	this->i = sc.i;
	this->f = sc.f;
	this->c = sc.c;
	return (*this);
}

ScalarConversion::~ScalarConversion( void )
{
}

int					ScalarConversion::getI( void )
{
	return this->i;
}

float				ScalarConversion::getF( void )
{
	return this->f;
}

double				ScalarConversion::getD( void )
{
	return this->d;
}

char				ScalarConversion::getC( void )
{
	return this->c;
}
ScalarConversion::ScalarConversion(ScalarConversion const &sc)
{
	this->c = sc.c;
	this->i = sc.i;
	this->f = sc.f;
	this->c = sc.c;
}