#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>

class NumNotFoundException: public std::exception
{
    public:
        const char* what() const throw()
        {
            return ("NumNotFoundException: Number not found"); 
        }
};

template <typename T>
typename T::iterator easyfind(T &my_container, int n) // const ?
{
    typename T::iterator it = std::find(my_container.begin(), my_container.end(), n);
    if ( it == my_container.end())
        throw NumNotFoundException();
    return (it);
}

#endif