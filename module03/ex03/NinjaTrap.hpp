#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
    public:
        NinjaTrap( void );
        NinjaTrap(std::string n);
        NinjaTrap(NinjaTrap & nt);
        ~NinjaTrap( void );
        void        getClapType();
        void        ninjaShoeBox(ClapTrap &cp);
        void        ninjaShoeBox(ScavTrap &cp);
        void        ninjaShoeBox(NinjaTrap &cp);
        void        ninjaShoeBox(FragTrap &cp);
        NinjaTrap & operator=(NinjaTrap const & Trap);

};
#endif