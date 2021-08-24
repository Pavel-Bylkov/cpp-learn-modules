#include "Karen.hpp"

int main(int ac, char *av[])
{
    Karen test = Karen();
    unsigned long long h = 0;

    if (ac == 2)
        h = s::hash(av[1]);
    switch (h)
    {
    case 210670746764:
        test.complain( "DEBUG" );
    case 6384151633:
        test.complain( "INFO" );
    case 229444843303835:
        test.complain( "WARNING" );
    case 210672417103:
        test.complain( "ERROR" );
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]";
        std::cout << std::endl;
        break;
	}

    return 0;
}
