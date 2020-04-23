#include "ScalarConversion.hpp"

int check_and_print_infinity(char *str)
{
    if (strcmp(str, "-inf") == 0 || strcmp(str, "-inff") == 0 || strcmp(str, "+inf") == 0 || strcmp(str, "+inff") == 0 || strcmp(str, "nan") == 0 || strcmp(str, "nanf") == 0)
    {
        ScalarConversion *sc = new ScalarConversion(str);
        (void)sc;
        return (1);
    }
    return (0);
}

int check_and_print_impossible(char *str)
{
    int cnt;
    cnt = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( str[i] == '.')
            cnt++;
        if (!isdigit(str[i]))
        {
            if (((str[i] == '.' && cnt > 1) && i > 0 )||\
            (!isdigit(str[i]) && i > 0 && (str[i] != '.' && str[i] != 'f')) ||
            (str[i] == 'f' && str[i+1] != '\0'))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                return (1);
            }
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Please input a literal to convert" << std::endl;
        return (1);
    }
    if (check_and_print_infinity(av[1]))
        return (0);
    if (check_and_print_impossible(av[1]))
        return (0);
    ScalarConversion *sc = new ScalarConversion(av[1]);
    (void)sc;
    return (0);
}