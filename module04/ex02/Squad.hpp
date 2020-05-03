#ifndef SQUAD_HPP
# define SQUAD_HPP
# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad: public ISquad
{
    private:
        ISpaceMarine**      units;
        int                 count;
    public:
        Squad();
        ~Squad();
        Squad(Squad const &squad);
        int getCount() const;
        ISpaceMarine* getUnit(int) const;
        int push(ISpaceMarine*);
        Squad &operator=(Squad const &squad);
};
#endif