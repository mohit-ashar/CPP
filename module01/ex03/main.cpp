#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main()
{
    std::string count;
    std::cout << "Enter the number of Zombizzzzzz in the horde..." << std::endl;
    std::getline (std::cin, count);
    int n = atoi(count.c_str());
    if (n > 0)
    {
        ZombieHorde *z1 = new ZombieHorde(n);
        z1->announce();
        delete z1;
        z1 = 0;
    }
    else
        std::cout << "Invalid number. Number should be greater than 0" << std::endl;
    return (0);
}