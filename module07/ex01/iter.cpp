#include <iostream>

template <typename T>
void    iter(T const *p, int const length, void(*f)(T const &ele))
{
    int i;

    i = 0;
    while (i < length)
    {
        f(p[i]);
        i++;
    }
}

template <typename T>
void    print_t(T const &x)
{
    std::cout << "Printing " << x << " from Templated print function" << std::endl;
}

void     print_dash(int const &c)
{
    std::cout << "-- " << c << std::endl;
}

void     print_dot(char const &c)
{
    std::cout << ".. " << c << std::endl;
}



int main( void )
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    iter(arr, 5, print_dash);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    char    c_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    iter(c_arr, 5, print_dot);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    iter(arr, 5, print_t);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    iter(c_arr, 5, print_t);
}