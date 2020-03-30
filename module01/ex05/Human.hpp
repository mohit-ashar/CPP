#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"
class Human: public Brain
{
    public:
        Brain const b;
        const Brain& getBrain() const;
        Human();
        std::string identify() const;
};
#endif