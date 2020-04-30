#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *string_ptr = &str;
    std::string &str_ref = str;

    std::cout << "String: " << str<< std::endl;
    std::cout << "String ptr: " << *string_ptr << std::endl;
    std::cout << "String ref: " << str_ref << std::endl;
}