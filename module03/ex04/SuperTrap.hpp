#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include "ScavTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap( void );
        SuperTrap( std::string n);
        SuperTrap( SuperTrap & st);
        ~SuperTrap( void );
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        SuperTrap & operator=(SuperTrap const & trap);

};

#endif