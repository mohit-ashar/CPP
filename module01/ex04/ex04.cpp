#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *string_ptr = &str;
    std::string &str_ref = str;

    std::cout << str<< std::endl;
    std::cout << *string_ptr << std::endl;
    std::cout << str_ref << std::endl;
}