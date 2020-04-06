#include "ScavTrap.hpp"


ScavTrap::ScavTrap( void ) : ScavTrap("Unnamed") 
{
    std::cout << "Default Constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string n)
{    
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 50;
    this->maxEnergyPoints = 50;
    this->level = 1;
    this->name = n;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->armorDamageReduction = 3;
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

int     ScavTrap::getHitPoints( void ) const
{
	return this->hitPoints;
}
void    ScavTrap::setHitPoints(int hp)
{
    if (hp <= 0)
        this->hitPoints = 0;
    else if (hp > this->getMaxHitPoints())
        this->hitPoints = this->getMaxHitPoints();
    else
	    this->hitPoints = hp;
}

int     ScavTrap::getMaxHitPoints( void ) const
{
    return this->maxHitPoints;
}

void    ScavTrap::setMaxHitPoints(int max_hp)
{
    this->maxHitPoints = max_hp;
}

int     ScavTrap::getEnergyPoints( void ) const
{
    return this->energyPoints;
}

void    ScavTrap::setEnergyPoints(int energy_points)
{
    if (energy_points > this->getMaxEnergyPoints())
        this->energyPoints = this->getMaxEnergyPoints();
    else
        this->energyPoints = energy_points;
}

int     ScavTrap::getMaxEnergyPoints( void ) const
{
    return this->maxEnergyPoints;
}

void    ScavTrap::setMaxEnergyPoints(int max_energy_points)
{
    this->maxEnergyPoints = max_energy_points;
}

int     ScavTrap::getLevel( void ) const
{
    return this->level;
}

void    ScavTrap::setLevel(int lvl)
{
    this->level = lvl;
}

std::string     ScavTrap::getName( void ) const
{
    return this->name;
}

void    ScavTrap::setName(std::string str)
{
    this->name = str;
}

int     ScavTrap::getMeleeAttackDamage( void ) const
{
    return this->meleeAttackDamage;
}

void    ScavTrap::setMeleeAttackDamage(int melee_damage)
{
    this->meleeAttackDamage = melee_damage;
}

int     ScavTrap::getRangedAttackDamage( void ) const
{
    return this->rangedAttackDamage;
}

void    ScavTrap::setRangedAttackDamage(int range_damage)
{
    this->rangedAttackDamage = range_damage;
}

int     ScavTrap::getArmorDamageReduction( void ) const
{
    return this->armorDamageReduction;
}

void    ScavTrap::setArmorDamageReduction(int armor_damage_reduction)
{
    this->armorDamageReduction = armor_damage_reduction;
}

void    ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "SC4V-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "SC4V-TP " << this->getName() << " Melee attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    int hp_left;
    amount = amount - this->getArmorDamageReduction();
    hp_left = this->getHitPoints() - amount;
    if (hp_left && (hp_left < (this->getMaxHitPoints() / 2)) && (this->energyPoints < (this->getMaxEnergyPoints() - 5)))
        this->setEnergyPoints(this->getEnergyPoints() + 5); 
    this->setHitPoints(hp_left);
    std::cout << "SC4V-TP " << this->getName() << " took a hit of " << amount << std::endl;
    std::cout << "SC4V-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    int hp_left = this->getHitPoints() + amount;
    this->setHitPoints(hp_left);
    std::cout << "SC4V-TP " << this->getName() << " HP repaired by " << amount << std::endl;
    std::cout << "SC4V-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() + 25);
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