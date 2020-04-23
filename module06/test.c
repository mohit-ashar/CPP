#include <iostream>

int main()
{
    char c;
    c = (char)10000;
    if (c > (char)127)
        std::cout << "Not Printable"
    else
        std::cout << c;
}