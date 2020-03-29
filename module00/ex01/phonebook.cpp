#include "phonebook.hpp"

void    Phonebook::display(Phonebook p, int size)
{
    int i;

    i = 0;
    std::cout << "|     index|first name| last name|  nickname|\n";
    while (i < size)
    {
        display_contact(p.c[i]);
        i++;
    }
}
