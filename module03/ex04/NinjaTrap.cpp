#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void )
{
    std::cout << "Default NinjaTrap constructor called." << std::endl;
    NinjaTrap("Unnamed");
}

NinjaTrap::NinjaTrap(std::string n): ClapTrap(60, 60, 120, 120, 1, n, 60, 5, 0)
{

	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->meleeAttackDamage = 60;
    std::cout << "N!NJ4-TP " << "Spawning " << n << " in Level: " << this->getLevel() <<" to take on the Mighty N!NJ4Trap!!!  (Parametric Constructor called)" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap & trap)
{
    *this = trap;
}

NinjaTrap::~NinjaTrap( void )
{
        std::cout << "N!NJ4-TP " << "Hahaha, destroyed N!NJ4! " << this->getName() << ". You ain't got the Power mate!!!  (Destructor called)" << std::endl;
}

void        NinjaTrap::getClapType()
{
    std::cout << "(I am a robot Ninja.)N!NJ4-TP" << std::endl;
}

void        NinjaTrap::ninjaShoeBox(ClapTrap &cp)
{
    std::cout << "Opening the box... Guess who appeared?" << std::endl;
    cp.getClapType();
}

void        NinjaTrap::ninjaShoeBox(ScavTrap &cp)
{
    std::cout << "Opening the box... Guess who appeared?" << std::endl;
    cp.getClapType();
}
void        NinjaTrap::ninjaShoeBox(NinjaTrap &cp)
{
    std::cout << "Opening the box... Guess who appeared?" << std::endl;
    cp.getClapType();
}
void        NinjaTrap::ninjaShoeBox(FragTrap &cp)
{
    std::cout << "Opening the box... Guess who appeared?" << std::endl;
    cp.getClapType();
}

NinjaTrap&       NinjaTrap::operator=(NinjaTrap const & trap)
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