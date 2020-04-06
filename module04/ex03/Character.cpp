#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string n) : name(n),materia{0,0,0,0},current_slot(0)
{

}

Character::~Character()
{
    int i;

    i = 0;
    while (i < this->current_slot)
    {
        if (this->materia[i] != 0)
            delete this->materia[i];
        i++;
    }
    // delete[] *this->materia;
}

Character::Character(Character & character)
{
    int i;

    i = 0;
    while (i < character.current_slot)
    {
        this->materia[i] = character.materia[i]->clone();
        i++;
    }
    this->name = character.name;
    this->current_slot = character.current_slot;
}

std::string const & Character::getName( void ) const
{
    return (this->name);
}

void                Character::equip(AMateria *m)
{
    if (this->current_slot == 4)
        return ;
    this->materia[current_slot] = m;
    this->current_slot++;
}

void                Character::unequip(int idx)
{
    if (this->current_slot < idx || idx < 0 || this->current_slot == 0)
        return ;
    this->materia[idx] = 0;
    this->current_slot--;
}

void                Character::use(int idx, ICharacter& target)
{
    if (this->current_slot < idx || idx < 0 || this->current_slot == 0)
        return ;
    this->materia[idx]->use(target);
}

Character & Character::operator=(Character const & character)
{
    int i;

    i = 0;
    // if (character.current_slot == 0)
    // {
    //     this->current_slot = character.current_slot;
    //     this->name = character.name;
    //     return (*this);
    // }
    while(i < this->current_slot)
    {
        delete this->materia[i];
        this->materia[i] = 0;
        i++;
    }
    i = 0;
    while(i < character.current_slot)
    {
        this->materia[i] = character.materia[i]->clone();
        i++;
    }
    this->current_slot = character.current_slot;
    this->name = character.name;
    return (*this);
}