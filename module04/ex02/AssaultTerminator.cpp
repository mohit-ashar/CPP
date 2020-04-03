#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & a_terminator)
{
    (void)a_terminator;
    std::cout << "* teleports from space *" << std::endl;
}


AssaultTerminator::~AssaultTerminator()
{
    std::cout <<  "I’ll be back..." << std::endl;
}

ISpaceMarine*       AssaultTerminator::clone() const
{
    return (new AssaultTerminator(*this));
}

void                AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void                AssaultTerminator::rangedAttack() const
{
    std::cout <<   "* does nothing *" << std::endl;
}

void                AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainﬁsts *"<< std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & a_terminator)
{
    (void)a_terminator;
    return(*this);
}