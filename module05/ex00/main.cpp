#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Tyrion Lannister", 148);
    std::cout << a;
    a.downgrade();
    std::cout << a;
    a.downgrade();
    std::cout << a;
    a.downgrade();
    std::cout << a;
    a.downgrade();
    std::cout << a;
    std::cout << "----------" << std::endl;

    Bureaucrat b("Jon Snow", -2);
    std::cout << b;
    b.upgrade();
    std::cout << b;
    b.upgrade();
    std::cout << b;
    std::cout << "----------" << std::endl;
    
    Bureaucrat c("Ramsay Boltom", 1);
    std::cout << c;
    c.downgrade();
    std::cout << c;
    c.upgrade();
    std::cout << c;
    c.upgrade();
    std::cout << c;
    std::cout << "----------" << std::endl;
}