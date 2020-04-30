#include <iostream>
#include <fstream>
#include <string>

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
    std::locale loc;

    if (av[1][0] == 0 || av[2][0] == 0 || av[3][0] == 0)
        return(strError("String cannot be empty", 1));
    std::string filename = av[1];
    for (std::string::size_type i=0; i<filename.length(); ++i)
        filename[i] = std::toupper(filename[i],loc);
    filename.append(".replace");
    if (!ifs.is_open())
        return(strError("File not found\n", 1));
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