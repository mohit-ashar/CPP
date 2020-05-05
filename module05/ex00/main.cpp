#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----------Contructor, assignment & copy----------"<< std::endl;
    Bureaucrat a("Tyrion Lannister", 148);
    Bureaucrat x = a;
    Bureaucrat y(x);
    std::cout << "Name of bureaucrat: " << a.getName() << std::endl;
    std::cout << "Grade of bureaucrat: " << a.getGrade() << std::endl;
    std::cout << a;
    std::cout << x;
    std::cout << y;
    
    std::cout << "\n----------Downgrading below grade 150----------"<< std::endl;
    try
    {
        a.downgrade();
        std::cout << a;
        a.downgrade();
        std::cout << a;
        a.downgrade();
        std::cout << a;
        a.downgrade();
        std::cout << a;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n----------Grade too low test----------"<< std::endl;
    try
    {
        Bureaucrat b("Jon Snow", 152);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------Grade too high test----------"<< std::endl;
    try
    {
        Bureaucrat b("Jon Snow", -2);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----------Upgrading above grade 1----------"<< std::endl;
    try
    {
        Bureaucrat c("Ramsay Boltom", 1);
        std::cout << c;
        c.downgrade();
        std::cout << c;
        c.upgrade();
        std::cout << c;
        c.upgrade();
        std::cout << c;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}