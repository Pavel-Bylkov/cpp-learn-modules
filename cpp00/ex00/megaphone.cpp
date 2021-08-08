#include <iostream>

void    print_args(int ac, char **av) 
{
    int i = 1;
    char *tmp;

    while (i < ac)
    {
        tmp = av[i++];
        while (*tmp)
        {
            std::cout << (char)std::toupper(*tmp);
            tmp++;
        }
    }
    std::cout << "\n";
}

int main(int ac, char **av)
{
    if (ac > 1)
        print_args(ac, av);
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
}
