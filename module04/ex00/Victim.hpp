#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
    protected:
        Victim( void );
        std::string name;
    public:
        Victim(std::string vicName);
        Victim(Victim & vic);
        virtual ~Victim( void );
        Victim & operator=(Victim const & src);
        std::string     getName( void ) const;
        void            setName(std::string vicName);
        virtual void    getPolymorphed( void ) const;
};

std::ostream & operator << (std::ostream & o, Victim  & vic);


#endif