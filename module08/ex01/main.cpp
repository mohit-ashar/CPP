#include "span.hpp"

int main()
{
Span sp = Span(10);
sp.addNumber(2147483647);
sp.addNumber(-2147483648);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}