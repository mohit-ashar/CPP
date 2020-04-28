#include "easyfind.hpp"
#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    std::list<int>::iterator it;
    it = lst.begin();
    while (it != lst.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    try
    {
        it = easyfind(lst, 10);
        while (it != lst.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    catch(NumNotFoundException e)
    {
        std::cout << e.what() << std::endl;

    }
    //Set
    //Vector
}