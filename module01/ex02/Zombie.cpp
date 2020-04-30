#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << "Arrrrggghhhhh.... Mr." << this->name << " shall R.I.P. Grave loss for the " << this->type << " type" << std::endl;
}

void    Zombie::announce()
{
    std::cout << "Braiiiiinzzzz, The name is " << name;
    std::cout << " and the type is " << type << ". What Sayyy?\n";
}

void    Zombie::setName(std::string z_name)
{
    name = z_name;
}

void    Zombie::setType(std::string z_type)
{
    type = z_type;
}

void    Zombie::randomChump()
{
    Zombie z;
    const std::string names[] = {"Gerrard", "Aguero", "Bernardo", "Suarez", "Fraudiola", "Torres", "Tevez"};
    const std::string types[] = {"scouser", "cheater", "biter", "diver"};
    z.setName(names[time(NULL) % 7]);
    z.setType(types[time(NULL) % 4]);
    z.announce();
}