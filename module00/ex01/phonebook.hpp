#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "contact.hpp"

class Phonebook: public Contact
{
    public:
        int size;
        Contact c[8];
        void    display(Phonebook p, int size);
};

#endif