#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    std::string count;
    std::cout << "Enter the number of Zombizzzzzz in the horde..." << std::endl;
    std::getline (std::cin, count);
    ZombieHorde *z1 = new ZombieHorde(atoi(count.c_str()));
    delete z1;
    z1 = 0;
}