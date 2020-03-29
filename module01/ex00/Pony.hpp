#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>
class Pony
{
    private:
        int height;
        std::string colour;
    public:
        void        set_height(int height);
        void        set_colour(std::string colour);
        int         get_height();
        std::string get_colour();
        void        display_msg(std:: string colour, int height);
};

#endif