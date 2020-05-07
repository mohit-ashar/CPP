#include "span.hpp"

int main()
{
    Span sp = Span(10);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);


    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "largest span: " << sp.longestSpan() << std::endl;
    std::cout << "-------------------------------\n";
    std::cout << "---------Checking with 10000 using iterators------\n";
    std::list<int> ten;
    for (int i = 0; i < 10000; i++)
    {
        ten.push_back(i);
    }
    Span sp2 = Span(10000);
    sp2.addNumber(ten.begin(), ten.end());
    std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "largest span: " << sp2.longestSpan() << std::endl;
    std::cout << "-------------------------------\n";
    std::cout << "---------Checking with container full------\n";
    try
    {
        sp.addNumber(ten.begin(), ten.end());
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "---------Checking with container empty------\n";
    try
    {
        Span sp3 = Span(0);
        std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "largest span: " << sp3.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
}
