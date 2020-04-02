#ifndef PEON_HPP
# define PEON_HPP
#include "Victim.hpp"

class Peon: public Victim
{
    private:
        Peon(void);

    public:
        Peon(std::string peon);
        Peon(Peon & peon);
        ~Peon();
        virtual void    getPolymorphed() const;
        Peon &          operator = (Peon const & peon);
};

#endif