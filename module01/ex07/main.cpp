#include <iostream>
#include <fstream>

int strError(std::string str, int ret)
{
    std::cout << str << std::endl;
    return (ret);
}
int main(int ac, char **av)
{
    if (ac != 4)
        return(strError("Incorrect number of arguments", 1));
    std::string find = av[2];
    std::string replace = av[3];
    std::ifstream ifs(av[1]);
    size_t n = 0;
    size_t find_len = find.size();

    if (av[1][0] == 0 || av[2][0] == 0 || av[3][0] == 0)
        return(strError("String cannot be empty", 1));
    std::string filename = av[1];
    filename.append(".replace");
    if (!ifs.is_open())
        return(strError("Invalid filename", 1));
    std::string str;
    std::getline( ifs, str, '\0');
    while ((n = str.find(find)) != std::string::npos)
        str.replace(n, find_len, replace);
    ifs.close();
    std::ofstream ofs(filename);
    ofs << str;
    ofs.close();
    return (0);
}