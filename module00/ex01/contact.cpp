#include "contact.hpp"

Contact    Contact::create(int ind)
{
    Contact c;
    c.index = ind;
    std::cout << "Please enter the following details..\n";
    std::cout << "Enter first name: ";
    std::getline (std::cin,c.first_name);
    if (c.first_name.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }

    std::cout << "Enter last name: ";
    std::getline (std::cin,c.last_name);
    if (c.last_name.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }

    std::cout << "Enter nick name: ";
    std::getline (std::cin,c.nick_name);
    if (c.nick_name.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }

    std::cout << "Enter login: ";
    std::getline (std::cin,c.login);
    if (c.login.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Enter postal address: ";
    std::getline (std::cin,c.postal_address);
    if (c.postal_address.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }

    std::cout << "Enter email address: ";
    std::getline (std::cin,c.email_address);
    if (c.email_address.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Enter phone number: ";
    std::getline (std::cin,c.phone_number);
    if (c.phone_number.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "birthday date(ex: 01/05/1995): ";
    std::getline (std::cin,c.birthday_date);
    if (c.birthday_date.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Enter favourite meal: ";
    std::getline (std::cin,c.favorite_meal);
    if (c.favorite_meal.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Enter underwear color: ";
    std::getline (std::cin,c.underwear_color);
    if (c.underwear_color.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Enter darkest secret: ";
    std::getline (std::cin,c.darkest_secret);
    if (c.darkest_secret.empty())
    {
        std::cout << "EOF!!!" << std::endl << "Shouldn't have done that\nOff you go. BYE :(" << std::endl;
        exit (0);
    }
    
    std::cout << "Contact added\n\n";
    return c;
}

void    Contact::display_field(std::string field)
{
    size_t size_field;
    int i;
    std::string sub;

    i = 0;
    size_field = field.size();
    if (size_field < 10)
    {
        while (i < (10 - (int)size_field))
        {
            std::cout << " ";
            i++;
        }
        std::cout << field; 
    }
    else if (size_field == 10)
        std::cout << field;
    else
    {
        sub = field.substr(0, 9);
        std::cout << sub;
        std::cout << ".";
    }
    std::cout << "|";
}

void    Contact::display_contact(Contact c)
{
    std::cout << "|         " << c.index;
    std::cout << "|";
    display_field(c.first_name);
    display_field(c.last_name);
    display_field(c.nick_name);
    std::cout << "\n";
}

void    Contact::display_contact_all(Contact c)
{
    std::cout << "\nfirst name: " << c.first_name << "\n";
    std::cout << "last name: " << c.last_name << "\n";
    std::cout << "nick name: " << c.nick_name << "\n";
    std::cout << "login: " << c.login << "\n";
    std::cout << "postal address: " << c.postal_address << "\n";
    std::cout << "email address: " << c.email_address << "\n";
    std::cout << "phone number: " << c.phone_number << "\n";
    std::cout << "birthday date: " << c.birthday_date << "\n";
    std::cout << "favorite meal: " << c.favorite_meal << "\n";
    std::cout << "underwear color: " << c.underwear_color << "\n";
    std::cout << "darkest secret: " << c.darkest_secret << "\n\n";

}
