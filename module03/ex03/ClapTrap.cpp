#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : ClapTrap(0, 0, 0, 0, 0, "unnamed", 0, 0,0)
{
    std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string n): ClapTrap(0, 0, 0, 0, 0, n, 0, 0, 0)
{

}

ClapTrap::ClapTrap(int hp, int max_hp, int energy_points, int max_energy_points, int lvl, std::string n, int melee_attack, int range_attack, int armor_damage_reduction)
{
    this->hitPoints = hp;
    this->maxHitPoints = max_hp;
    this->energyPoints = energy_points;
    this->maxEnergyPoints = max_energy_points;
    this->level = lvl;
    this->name = n;
    this->meleeAttackDamage = melee_attack;
    this->rangedAttackDamage = range_attack;
    this->armorDamageReduction = armor_damage_reduction;
    std::cout << "CL4P-TP " << "Spawning " << n << " in Level: " << this->getLevel() <<" to take on the Mighty Parent ClapTrap!!!  (Parametric Constructor called)" << std::endl;

}

ClapTrap::ClapTrap(ClapTrap & trap)
{
    *this = trap;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "CL4P-TP " << "ClaaaaapTraaaaap destroyed " << this->getName() << ". BOOOOOOM!!!  (Destructor called)" << std::endl;
}

int ClapTrap::getHitPoints( void )
{
    return (this->hitPoints);
}

void    ClapTrap::setHitPoints(int hp)
{
    if (hp <= 0)
        this->hitPoints = 0;
    else if (hp > this->getMaxHitPoints())
        this->hitPoints = this->getMaxHitPoints();
    else
	    this->hitPoints = hp;
}

int     ClapTrap::getMaxHitPoints( void )
{
    return (this->maxHitPoints);
}

void    ClapTrap::setMaxHitPoints(int max_hp)
{
    this->maxHitPoints = max_hp;
}

int     ClapTrap::getEnergyPoints( void )
{
    return (this->energyPoints);
}

void    ClapTrap::setEnergyPoints(int energy_points)
{
     if (energy_points > this->getMaxEnergyPoints())
        this->energyPoints = this->getMaxEnergyPoints();
    else
        this->energyPoints = energy_points;
}

int     ClapTrap::getMaxEnergyPoints( void )
{
    return (this->maxEnergyPoints);
}

void    ClapTrap::setMaxEnergyPoints( int max_energy_points)
{
    this->maxEnergyPoints = max_energy_points;
}

int     ClapTrap::getLevel( void )
{
    return this->level;
}

void    ClapTrap::setLevel(int lvl)
{
    this->level = lvl;
}

std::string     ClapTrap::getName( void )
{
    return this->name;
}

void    ClapTrap::setName(std::string str)
{
    this->name = str;
}

int     ClapTrap::getMeleeAttackDamage( void )
{
    return this->meleeAttackDamage;
}

void    ClapTrap::setMeleeAttackDamage(int melee_damage)
{
    this->meleeAttackDamage = melee_damage;
}

int     ClapTrap::getRangedAttackDamage( void )
{
    return this->rangedAttackDamage;
}

void    ClapTrap::setRangedAttackDamage(int range_damage)
{
    this->rangedAttackDamage = range_damage;
}

int     ClapTrap::getArmorDamageReduction( void )
{
    return this->armorDamageReduction;
}

void    ClapTrap::setArmorDamageReduction(int armor_damage_reduction)
{
    this->armorDamageReduction = armor_damage_reduction;
}

void    ClapTrap::rangedAttack(std::string const & target)
{
    std::cout << "CL4P-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
}

void    ClapTrap::meleeAttack(std::string const & target)
{
    std::cout << "CL4P-TP " << this->getName() << " Melee attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    int hp_left;
    amount = amount - this->getArmorDamageReduction();
    hp_left = this->getHitPoints() - amount;
    if (hp_left && (hp_left < (this->getMaxHitPoints() / 2)) && (this->energyPoints < (this->getMaxEnergyPoints() - 5)))
        this->setEnergyPoints(this->getEnergyPoints() + 5); 
    this->setHitPoints(hp_left);
    std::cout << "CL4P-TP " << this->getName() << " took a hit of " << amount << std::endl;
    std::cout << "CL4P-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    int hp_left = this->getHitPoints() + amount;
    this->setHitPoints(hp_left);
    std::cout << "CL4P-TP " << this->getName() << " HP repaired by " << amount << std::endl;
    std::cout << "CL4P-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() + 25);
}

void    ClapTrap::getClapType()
{
        std::cout << "(I am trap..Clap trap)CL4P-TP" << std::endl;
}