#include "Zombie.hpp"

int main( void )
{
    Zombie* horde;

    horde = zombieHorde(42, "newZombie");

	for (int i = 0; i < 42; ++i)
		horde[i].announce();

    delete [] horde;

    return 0;
}