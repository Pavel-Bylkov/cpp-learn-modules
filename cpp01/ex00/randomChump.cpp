#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie chump = Zombie(name);
    chump.announce();
    return;
}

void announceZombie( Zombie *zomb)
{
    zomb->announce();
    return;
}
