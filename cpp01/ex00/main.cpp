#include "Zombie.hpp"

int main(void)
{
    Zombie *one;

    one = newZombie("Vasiliy");
    announceZombie(one);

    randomChump("Petr");

    delete one;
    return 0;
}