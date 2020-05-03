#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
    private:
        Character();
        std::string name;
        AMateria*   materia[4];
        int         current_slot;
    public:
        Character(std::string n);
        Character(Character &character);
        ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        Character & operator=(Character const & character);
};
#endif