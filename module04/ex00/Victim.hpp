#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
    private:
        Victim(void);
        std::string name;
    public:
        Victim(std::string vicName);
        Victim(Victim & vic);
        ~Victim();
        Victim & operator = (Victim const & src);
        std::string     getName() const;
        void            setName(std::string vicName);
        virtual void            getPolymorphed() const;
};

std::ostream & operator << (std::ostream & o, Victim  & vic);


#endif