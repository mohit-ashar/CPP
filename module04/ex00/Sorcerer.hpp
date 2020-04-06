#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"
# include "Peon.hpp"
class Sorcerer
{
    private:
        Sorcerer(void);
        std::string name;
        std::string title;
    public:
        Sorcerer(std::string sorcName, std::string sorcTitle);
        Sorcerer(Sorcerer & src);
        ~Sorcerer( void );
        Sorcerer &  operator = (Sorcerer const & src);
        std::string getName( void ) const;
        std::string getTitle( void ) const;
        void        setName(std::string name);
        void        setTitle(std::string title);
        void        polymorph(Victim const & vic) const;
};
std::ostream & operator << (std::ostream & o, Sorcerer  & src);
#endif