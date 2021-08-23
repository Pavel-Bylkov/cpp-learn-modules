#include "replace.hpp"

int main(int ac, char *av[])
{
    if (ac != 4) {
        std::cerr << "Error: Number of arguments\n";
        return 1;
    }
    if (replace_infile(av[1], av[2], av[3]))
        return 1;
    return 0;
}