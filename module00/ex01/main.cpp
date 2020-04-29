#include "phonebook.hpp"
#include <signal.h>

int main()
{
    int i;
    std::string num;
    std::string input;

    i = 0;
    Phonebook p;
    p.size = 0;
    while (1)
    {
        std::cout << "Choose appropriate option:\nADD\nSEARCH\nEXIT\n>";
        std::getline (std::cin, input);
        if (input.empty())
        {
            std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
            return (1);
        }
        if (input.compare("ADD") == 0)
        {
            if (i > 7)
            {
                i = (i % 8);
                p.c[i] = p.c[i].create(i + 1);
                p.size = 8;
                i++;
            }
            else
            {
                p.c[i] = p.c[i].create(i + 1);
                if (p.size != 8)
                    p.size = i + 1;
                i++;
            }
                   
        }
        else if (input.compare("SEARCH") == 0)
        {
            if (p.size == 0)
            {
                std::cout <<"Phonebook empty\n\n";
                continue;
            }
            p.display(p, p.size);
            std::cout << "\nEnter a valid index for contact details: ";
            std::getline (std::cin, num);
            if (num.size() > (size_t)8 || num[0] < '0' || num[0] > (p.size + '0') ||num[0] > '8')
                std::cout << "Invalid index\n\n";
            else
                p.display_contact_all(p.c[num[0] - '0' - 1]);
        }
        else if (input.compare("EXIT") == 0)
            exit(0);
        else
            std::cout << "Incorrect choice\n";

    }
    
}