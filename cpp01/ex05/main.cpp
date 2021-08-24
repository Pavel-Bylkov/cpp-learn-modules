#include "Karen.hpp"

int main(int ac, char *av[])
{
    Karen test = Karen();

    test.complain( "DEBUG" );
    test.complain( "INFO" );
    test.complain( "WARNING" );
    test.complain( "ERROR" );
    return 0;
}