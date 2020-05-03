#include "Squad.hpp"

Squad::Squad() : units(NULL),count(0)
{
}

Squad::~Squad()
{
    int i;

    i = 0;
    if (this->units)
    {
        while (i < this->count)
        {
            delete this->units[i];
            i++;
        }
    }
    delete[] this->units;
}

Squad::Squad(Squad const & squad)
{
    int i;

    i = 0;
    int n = squad.getCount();
    if (squad.units)
    {
        this->units = new ISpaceMarine *[count];
        while (i < n)
        {
            this->units[i] = squad.getUnit(i)->clone();
            i++;
        }
    }
    else
        this->units = NULL;
    this->count = n;
}

int     Squad::getCount() const
{
    return (this->count);
}

ISpaceMarine*   Squad::getUnit(int n) const
{
    if (n >= 0 && n < this->count)
        return (this->units[n]);
    return (0);
}

int     Squad::push(ISpaceMarine* marine)
{
    ISpaceMarine **new_unit;
    int i;

    i = 0;
    if (marine == 0)
        return (this->count);
    while (i < this->count)
    {
        if (this->units[i] == marine)
            return (this->count);
        i++;
    }
    if (!(new_unit = new ISpaceMarine*[this->count + 1]))
        return (this->count);
    i = 0;
    while(i < this->count)
    {
        new_unit[i] = this->units[i];
        i++;
    }
    new_unit[i] = marine;
    delete[] this->units;
    this->units = new_unit;
    this->count++;
    return (this->count);
}

Squad &Squad::operator=(Squad const &squad)
{
    std::cout << "Here\n";
    int i;

    i = 0;
    if (this->units)
    {
        while (i < this->count)
        {
            delete this->units[i];
            i++;
        }
        delete[] this->units;
        this->count = 0;
        // this->units = NULL;
        i = 0;
        while (i < squad.count)
        {
            this->push(squad.getUnit(i)->clone());
            i++;
        }
    }
    return (*this);
}