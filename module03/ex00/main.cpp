#include "FragTrap.hpp"

int main()
{
    FragTrap andy("andy");
    FragTrap zoo("zoo");

    andy.rangedAttack(zoo.getName());
    zoo.takeDamage(andy.getRangedAttackDamage());
    
    zoo.meleeAttack(andy.getName());
    andy.takeDamage(zoo.getMeleeAttackDamage());
    
    andy.vaulthunter_dot_exe(zoo.getName());
    
    zoo.meleeAttack(andy.getName());
    andy.takeDamage(zoo.getMeleeAttackDamage());
    
    andy.vaulthunter_dot_exe(zoo.getName());
    andy.vaulthunter_dot_exe(zoo.getName());
    andy.vaulthunter_dot_exe(zoo.getName());
    andy.vaulthunter_dot_exe(zoo.getName());
    
    andy.beRepaired(25);

}