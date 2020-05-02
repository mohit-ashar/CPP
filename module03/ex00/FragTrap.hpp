#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <ctime>

class FragTrap
{
    private:
        int         hitPoints;
        int         maxHitPoints;
        int         energyPoints;
        int         maxEnergyPoints;
        int         level;
        std::string name;
        int         meleeAttackDamage;
        int         rangedAttackDamage;
        int         armorDamageReduction;
    public:
        FragTrap();
        FragTrap(std::string n);
        FragTrap(FragTrap & trap);
        ~FragTrap();

        int         getHitPoints( void ) const;
        int         getMaxHitPoints( void ) const;
        int         getEnergyPoints( void ) const;
        int         getMaxEnergyPoints( void ) const;
        int         getLevel( void ) const;
        std::string getName( void ) const;
        int         getMeleeAttackDamage( void ) const;
        int         getRangedAttackDamage( void ) const;
        int         getArmorDamageReduction( void ) const;

        void        setHitPoints(int hp);
        void        setMaxHitPoints(int max_hp);
        void        setEnergyPoints(int energy_points);
        void        setMaxEnergyPoints(int max_energy_points);
        void        setLevel(int lvl);
        void        setName(std::string str);
        void        setMeleeAttackDamage(int melee_damage);
        void        setRangedAttackDamage(int ranged_damage);
        void        setArmorDamageReduction(int armor_damage__reduction);

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        vaulthunter_dot_exe(std::string const & target);
        FragTrap &  operator=(FragTrap const & trap);
};
#endif