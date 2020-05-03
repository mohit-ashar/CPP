#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria        *memory[4];
        int             current_slot;
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &ms);
        virtual void        learnMateria(AMateria* a);
        virtual AMateria*   createMateria(std::string const &type);
        MateriaSource &operator=(MateriaSource const &ms);
};

#endif