#include "Pony.hpp"

void Pony::display_msg(std::string colour, int height)
{
    std::cout << "Neigh, I am a " << colour << " pony and my height is " << height << " cms.\n\n";
}

void     Pony::set_height(int ht)
{
    height = ht;
}

void     Pony::set_colour(std::string clr)
{
    colour = clr;
}

int     Pony::get_height()
{
    return (height);
}

std::string     Pony::get_colour()
{
    return(colour);
}