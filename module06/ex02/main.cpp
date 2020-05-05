#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    Base *base;
    srand(time(NULL));
    int x = rand() % 3;
    if (x == 0)
        base = new A();
    else if (x == 1)
        base = new B();
    else
        base = new C();
    return (base);
}

void identify_from_reference(Base & p)
{
    Base *b = &p;
    Base *a1 = dynamic_cast<A*>(b);
    if (a1 != NULL)
        std::cout << "Base is of the type A" << std::endl;
    else
    {
        a1 = dynamic_cast<B*>(b);
        if (a1 != NULL)
            std::cout << "Base is of the type B" << std::endl;
        else
            std::cout << "Base is of the type C" << std::endl;
    }
}

void identify_from_pointer(Base * p)
{
    Base *a1 = dynamic_cast<A*>(p);
    if (a1 != NULL)
        std::cout << "Base is of the type A" << std::endl;
    else
    {
        a1 = dynamic_cast<B*>(p);
        if (a1 != NULL)
            std::cout << "Base is of the type B" << std::endl;
        else
            std::cout << "Base is of the type C" << std::endl;
    }
}

int main()
{
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
}