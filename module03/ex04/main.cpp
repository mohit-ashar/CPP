#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
    SuperTrap andy("andy");
    std::cout << andy.getHitPoints();
    NinjaTrap bob("bobby");
    ClapTrap techmax("techmax");
    ScavTrap mg("mg");

    SuperTrap zoo("zoo");
    andy.rangedAttack(zoo.getName());
    zoo.takeDamage(andy.getRangedAttackDamage());
    zoo.meleeAttack(andy.getName());
    andy.takeDamage(zoo.getMeleeAttackDamage());
    andy.vaulthunter_dot_exe(zoo.getName());
    zoo.meleeAttack(andy.getName());
    andy.takeDamage(zoo.getMeleeAttackDamage());
    andy.vaulthunter_dot_exe(zoo.getName());
    andy.beRepaired(25);


    std::cout << "\n\n---------------------------\n\n";

    ScavTrap max("Max");
    ScavTrap tom("Tom");
    max.rangedAttack(tom.getName());
    tom.takeDamage(max.getRangedAttackDamage());
    tom.meleeAttack(max.getName());
    max.takeDamage(tom.getMeleeAttackDamage());
    max.challengeNewcomer(tom.getName());
    tom.meleeAttack(max.getName());
    max.takeDamage(tom.getMeleeAttackDamage());
    max.challengeNewcomer(tom.getName());
    max.beRepaired(25);

}