#include "FragTrap.hpp"


FragTrap::FragTrap( void ) : FragTrap("Unnamed") 
{
    std::cout << "Default Constructor called." << std::endl;
}

FragTrap::FragTrap(std::string n)
{    
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->name = n;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
    std::cout << "FR4G-TP " << "Spawning " << n << " in Level: " << this->getLevel() <<" Fight!!!  (Parametric Constructor called)" << std::endl;
}

FragTrap::FragTrap(FragTrap & trap)
{
    *this = trap;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FR4G-TP " << "Apocalypse destroyed " << this->getName() << ". AMEN!!!  (Destructor called)" << std::endl;
}

int     FragTrap::getHitPoints( void ) const
{
	return this->hitPoints;
}
void    FragTrap::setHitPoints(int hp)
{
    if (hp <= 0)
        this->hitPoints = 0;
    else if (hp > this->getMaxHitPoints())
        this->hitPoints = this->getMaxHitPoints();
    else
	    this->hitPoints = hp;
}

int     FragTrap::getMaxHitPoints( void ) const
{
    return this->maxHitPoints;
}

void    FragTrap::setMaxHitPoints(int max_hp)
{
    this->maxHitPoints = max_hp;
}

int     FragTrap::getEnergyPoints( void ) const
{
    return this->energyPoints;
}

void    FragTrap::setEnergyPoints(int energy_points)
{
    if (energy_points > this->getMaxEnergyPoints())
        this->energyPoints = this->getMaxEnergyPoints();
    else
        this->energyPoints = energy_points;
}

int     FragTrap::getMaxEnergyPoints( void ) const
{
    return this->maxEnergyPoints;
}

void    FragTrap::setMaxEnergyPoints(int max_energy_points)
{
    this->maxEnergyPoints = max_energy_points;
}

int     FragTrap::getLevel( void ) const
{
    return this->level;
}

void    FragTrap::setLevel(int lvl)
{
    this->level = lvl;
}

std::string     FragTrap::getName( void ) const
{
    return this->name;
}

void    FragTrap::setName(std::string str)
{
    this->name = str;
}

int     FragTrap::getMeleeAttackDamage( void ) const
{
    return this->meleeAttackDamage;
}

void    FragTrap::setMeleeAttackDamage(int melee_damage)
{
    this->meleeAttackDamage = melee_damage;
}

int     FragTrap::getRangedAttackDamage( void ) const
{
    return this->rangedAttackDamage;
}

void    FragTrap::setRangedAttackDamage(int range_damage)
{
    this->rangedAttackDamage = range_damage;
}

int     FragTrap::getArmorDamageReduction( void ) const
{
    return this->armorDamageReduction;
}

void    FragTrap::setArmorDamageReduction(int armor_damage_reduction)
{
    this->armorDamageReduction = armor_damage_reduction;
}

void    FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
}

void    FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "FR4G-TP " << this->getName() << " Melee attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    int hp_left;
    amount = amount - this->getArmorDamageReduction();
    hp_left = this->getHitPoints() - amount;
    if (hp_left && (hp_left < (this->getMaxHitPoints() / 2)) && (this->energyPoints < (this->getMaxEnergyPoints() - 5)))
        this->setEnergyPoints(this->getEnergyPoints() + 5); 
    this->setHitPoints(hp_left);
    std::cout << "FR4G-TP " << this->getName() << " took a hit of " << amount << std::endl;
    std::cout << "FR4G-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount)
{
    int hp_left = this->getHitPoints() + amount;
    this->setHitPoints(hp_left);
    std::cout << "FR4G-TP " << this->getName() << " HP repaired by " << amount << std::endl;
    std::cout << "FR4G-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() + 25);
}

void            FragTrap::vaulthunter_dot_exe(std::string const & target)
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