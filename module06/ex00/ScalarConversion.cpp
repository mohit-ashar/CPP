#include  "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(char *str)
{
    errno = 0;
    this->d = strtod(str, NULL);
    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    this->f = strtof(str, NULL);
    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: "<< this->d; 
        if (this->d - floor(this->d) == 0)
            std::cout << ".0";
        std::cout << std::endl;
        return ;
    }

    if (this->f > 2147483647.0 || this->f < -2147483648.0 || !strcmp(str, "nan") || !strcmp(str, "nanf"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        this->i = (int)this->f;
        if ( this->i < 32 || this->i > 126)
            std::cout << "char: Not Displayable" << std::endl;
        else
        {
            this->c = (char)this->i;
            std::cout << "char: " << this->c << std::endl;
        }
        std::cout << "int: " << this->i << std::endl;
    }
    std::cout << "float: " << this->f;
    if (this->f - floor(this->f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << this->d;
    if (this->d - floor(this->d) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

ScalarConversion & ScalarConversion::operator=(ScalarConversion const & sc)
{
    this->c = sc.c;
    this->i = sc.i;
    this->f = sc.f;
    this->c = sc.c;
    return (*this);
}