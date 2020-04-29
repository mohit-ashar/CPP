#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"
class Human: public Brain
{
    private:
        Brain const b;
    public:
        Human();
        const Brain& getBrain() const;
        std::string identify() const;
};
#endif