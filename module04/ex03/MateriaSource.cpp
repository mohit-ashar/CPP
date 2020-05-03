#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : memory{0,0,0,0},current_slot(0)
{
}

MateriaSource::~MateriaSource()
{
    int i;

    i = 0;
    while (i < this->current_slot)
    {
        if (this->memory[i] != 0)
            delete this->memory[i];
        i++;
    }
}

MateriaSource::MateriaSource(MateriaSource const &ms)
{
    int i;

    i = 0;
    while (i < ms.current_slot)
    {
        this->memory[i] = ms.memory[i]->clone();
        i++;
    }
    while (i < 4)
    {
        this->memory[i] = 0;
        i++;
    }
    this->current_slot = ms.current_slot;
}

void            MateriaSource::learnMateria(AMateria *m)
{
    if (this->current_slot == 4 || !m)
		return;
    this->memory[this->current_slot] = m;
    this->current_slot++;
}

AMateria*            MateriaSource::createMateria(std::string const &type)
{
    int i;
    i = 0;

    while (i < this->current_slot)
    {
        if (this->memory[i]->getType() == type)
            return (this->memory[i]->clone()); 
        i++;
    }
    return (0);
}

MateriaSource   &MateriaSource::operator=(MateriaSource const &ms)
{
    int i;

    i = 0;
    while (i < this->current_slot)
    {
        delete this->memory[i];
        this->memory[i] = 0;
        i++;
    }
    i = 0;
    while (i < ms.current_slot)
    {
        this->memory[i] = ms.memory[i]->clone();
        i++;
    }
    this->current_slot = ms.current_slot;
    return (*this);
}