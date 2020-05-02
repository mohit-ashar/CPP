#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap(0, 0, 0, 0, 1, "unnamed",0 ,0 ,0)
{
    std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string n): ClapTrap(100, 100, 100, 100, 1, n, 30, 20, 5)
{
    std::cout << "FR4G-TP " << "Spawning " << n << " in Level: " << this->getLevel() <<" to take on the Fragger Boi!!!  (Parametric Constructor called)" << std::endl;
}

FragTrap::FragTrap(FragTrap & trap)
{
    *this = trap;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FR4G-TP " << "Apocalypse destroyed " << this->getName() << ". AMEN!!!  (Destructor called)" << std::endl;
}


void    FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    if(this->getEnergyPoints() < 25)
    {
        std::cout << "FR4G-TP "<< this->getName() << ", Get some energy first man!" << std::endl;
        return ;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 25);
    std::string str[5] = 
    {
        " was hit by Magicarp Splash. Took a damage of 0 points. Bleh",
        " was hit by Charizard Fireball. Took a damage of 50 points. Burn",
        " was hit my Pikachu Thundershock. Took a damage of 40. Electric",
        " was hit by Blastoise Water Gun. Took a damage of 45. Wet",
        " was hit by Jigglypuff song. Took a damage of 5. ZZZZzzzzzzz"
    };
    srand(time(NULL) * rand());
    std::cout << "FR4G-TP " << target << str[rand() % 5] << std::endl;
    return ;
}

void    FragTrap::getClapType()
{
        std::cout << "(Get ready for some FragTrap Facetime...)FR4G-TP" << std::endl;
}

FragTrap&       FragTrap::operator=(FragTrap const & trap)
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