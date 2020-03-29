#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
class Contact
{
    private:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string login;
        std::string postal_address;
        std::string email_address;
        std::string phone_number;
        std::string birthday_date;
        std::string favorite_meal;
        std::string underwear_color;
        std::string darkest_secret;
    public:
        Contact create(int index);
        void    display_field(std::string field);
        void    display_contact(Contact c);
        void    display_contact_all(Contact c);

};

#endif