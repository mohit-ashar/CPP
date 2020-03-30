#include "Human.hpp"

Human::Human() : b()
{

}

const Brain&  Human::getBrain() const
{
    return (this->b);
}

std::string Human::identify() const
{
    return (this->b.identify());
}