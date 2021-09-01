#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap p("Petr");
    DiamondTrap c;

    p.attack("Monster1");
    p.beRepaired(2);
    p.takeDamage(5);
    p.highFivesGuys();

    c = p;
    c.attack("Monster2");
    c.beRepaired(2);
    c.takeDamage(5);
    c.guardGate();

    c.whoAmI();

    return 0;
}