#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap p("Petr");
    ScavTrap c;

    p.attack("Monster1");
    p.beRepaired(2);
    p.takeDamage(5);
    p.guardGate();

    c = p;
    c.attack("Monster2");
    c.beRepaired(2);
    c.takeDamage(5);

    return 0;
}