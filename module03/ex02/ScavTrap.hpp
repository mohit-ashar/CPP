#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap( std::string n);
        ScavTrap(ScavTrap & st);
        ~ScavTrap( void );
        void        challengeNewcomer(std::string const & target);
        ScavTrap &  operator=(ScavTrap const & trap);
};

#endif