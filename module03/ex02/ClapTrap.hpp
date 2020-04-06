#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <ctime>

class ClapTrap
{
    protected:
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
        ClapTrap();
        ClapTrap(int hp, int max_hp, int energy_points, int max_energy_points, int lvl, std::string n, int melee_attack, int range_attack, int armor_damage_reduction);
        ClapTrap(ClapTrap & trap);
        ~ClapTrap();

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
        ClapTrap &  operator=(ClapTrap const & trap);
};

#endif