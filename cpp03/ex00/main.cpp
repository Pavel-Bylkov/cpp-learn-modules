#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap p("Petr");

    p.attack("Monster");
    p.beRepaired(2);
    p.takeDamage(5);

    return 0;
}