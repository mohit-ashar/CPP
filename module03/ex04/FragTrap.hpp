#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap( std::string n);
        FragTrap(FragTrap & ft);
        ~FragTrap( void );
        void        vaulthunter_dot_exe(std::string const & target);
        void        getClapType();
        FragTrap & operator=(FragTrap const & FragTrap);
};

#endif