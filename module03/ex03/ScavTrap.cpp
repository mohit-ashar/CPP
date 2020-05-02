#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap(0, 0, 0, 0, 1, "unnamed",0 ,0 ,0)
{
    std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string n): ClapTrap(100, 100, 50, 50, 1, n, 20, 15, 3)
{
    std::cout << "SC4V-TP " << "Spawning " << n << " in Level: " << this->getLevel() <<" to take on the Mighty ScavTrap!!!  (Parametric Constructor called)" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap & trap)
{
    *this = trap;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "SC4V-TP " << "Hahaha, destroyed challenger " << this->getName() << ". You ain't got the Power mate!!!  (Destructor called)" << std::endl;
}

void    ScavTrap::challengeNewcomer(std::string const & target)
{
    if(this->getEnergyPoints() < 25)
    {
        std::cout << "SC4V-TP "<< this->getName() << ", Get some energy first man!" << std::endl;
        return ;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 25);
    std::string str[5] = 
    {
        " is challenged to fight Jon Snow. You know nothing..",
        " is challenged to steal Khaleesi's Dragons. Dracarys..",
        " is challenged to a drinking batlle against Tyrion. Imp..",
        " is challenged to find Arya. No one..",
        " is chllaenged to serve Ramsay Bolton. Torture.."
    };
    srand(time(NULL) * rand());
    std::cout << "SC4V-TP " << target << str[rand() % 5] << std::endl;
    return ;
}

void    ScavTrap::getClapType()
{
    std::cout << "Halt Moon Citizen!!" << "SC4V-TP" << std::endl;
}

ScavTrap &   ScavTrap::operator=(ScavTrap const & trap)
{
    this->setHitPoints(trap.getHitPoints());
    this->setMaxEnergyPoints(trap.getMaxEnergyPoints());
    this->setEnergyPoints(trap.getEnergyPoints());
    this->setMaxHitPoints(trap.getMaxHitPoints());
    this->setLevel(trap.getLevel());
    this->setName(trap.getName());
    this->setMeleeAttackDamage(trap.getMeleeAttackDamage());
    this->setRangedAttackDamage(trap.getRangedAttackDamage());
    this->setArmorDamageReduction(trap.getArmorDamageReduction());
    return (*this);
}