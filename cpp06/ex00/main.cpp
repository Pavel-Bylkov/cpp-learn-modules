#include "Convert.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        return 1;
    }
    try
    {
        Convert conv(av[1]);
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}