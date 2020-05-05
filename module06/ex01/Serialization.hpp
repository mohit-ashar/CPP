#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
#include <iostream>

class Serialization
{
    public:
        struct  Data
            {
                std::string s1;
                int         n;
                std::string s2;
            } data;
        Serialization( void );
        ~Serialization( void );
        Serialization( Serialization const & s );
        Serialization & operator=(Serialization const & s);
        void*   serialize( void );
        Data*   deserialize( void *p );
        std::string    gen_random(const int len);
};
#endif