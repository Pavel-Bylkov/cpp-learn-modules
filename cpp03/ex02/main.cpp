#include "FragTrap.hpp"

int main( void )
{
    FragTrap p("Petr");
    FragTrap c;

    p.attack("Monster1");
    p.beRepaired(2);
    p.takeDamage(5);
    p.highFivesGuys();

    c = p;
    c.attack("Monster2");
    c.beRepaired(2);
    c.takeDamage(5);

    return 0;
}