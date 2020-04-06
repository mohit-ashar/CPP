#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void ): ClapTrap(), FragTrap(), NinjaTrap()
{
    std::cout << "Default SuperTrap constructor called";
}

SuperTrap::SuperTrap( std::string n): ClapTrap(n), FragTrap(n), NinjaTrap(n)
{
    this->hitPoints = this->FragTrap::hitPoints;
    this->maxHitPoints = this->FragTrap::maxHitPoints;
    this->energyPoints = this->NinjaTrap::energyPoints;
    this->maxEnergyPoints = this->NinjaTrap::maxEnergyPoints;
    this->level = 1;
    this->name = n;
    this->meleeAttackDamage = this->NinjaTrap::meleeAttackDamage;
    this->rangedAttackDamage = this->FragTrap::rangedAttackDamage;
    this->armorDamageReduction = this->FragTrap::armorDamageReduction;
    std::cout << "SUPER-TP The painful SuperTrap is now ready" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap & trap)
{
    *this = trap;
}

SuperTrap::~SuperTrap( void )
{
    std::cout << "SUPER-TP SuperTrap destroyed " << this->getName() << ". Suuuuper cool!" << std::endl;
}

void    SuperTrap::rangedAttack(std::string const & target)
{
    std::cout << "SUPER-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
}

void    SuperTrap::meleeAttack(std::string const & target)
{
    std::cout << "SUPER-TP " << this->getName() << " Melee attacks " << target << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
}

void    SuperTrap::takeDamage(unsigned int amount)
{
    int hp_left;
    amount = amount - this->getArmorDamageReduction();
    hp_left = this->getHitPoints() - amount;
    if (hp_left && (hp_left < (this->getMaxHitPoints() / 2)) && (this->energyPoints < (this->getMaxEnergyPoints() - 5)))
        this->setEnergyPoints(this->getEnergyPoints() + 5); 
    this->setHitPoints(hp_left);
    std::cout << "SUPER-TP " << this->getName() << " took a hit of " << amount << std::endl;
    std::cout << "SUPER-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
}

void    SuperTrap::beRepaired(unsigned int amount)
{
    int hp_left = this->getHitPoints() + amount;
    this->setHitPoints(hp_left);
    std::cout << "SUPER-TP " << this->getName() << " HP repaired by " << amount << std::endl;
    std::cout << "SUPER-TP " << this->getName() << " HP remaining: " << this->getHitPoints() << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() + 25);
}

SuperTrap&       SuperTrap::operator=(SuperTrap const & trap)
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