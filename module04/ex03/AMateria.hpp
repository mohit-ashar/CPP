#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
    private:
        AMateria( void );
        unsigned        int _xp;
    protected:
        std::string     materiaType;
    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & am);
        virtual ~AMateria();
        std::string const &getType() const;
        void        setType(std::string type);
        unsigned int getXP() const;
        void         setXP(unsigned int xp);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
        AMateria &operator=(AMateria const &am);
};


#endif