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
        std::cout << *it << " ";
        it++;
    }
    try
    {
        std::cout << "\n#------Number exists case:";
        it = easyfind(lst, 3);
        std::cout << "Number found, your number is " <<  *it <<" and the elements from your number are: \n";
        while (it != lst.end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "\n#------Number doesn't exist case:\n";
        it = easyfind(lst, 13);
    }
    catch(NumNotFoundException e)
    {
        std::cout << e.what() << std::endl;

    }
}