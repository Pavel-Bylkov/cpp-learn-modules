#include "Karen.hpp"

int main( void )
{
    Karen test = Karen();

    test.complain( "DEBUG" );
    test.complain( "INFO" );
    test.complain( "WARNING" );
    test.complain( "ERROR" );
    return 0;
}