#ifndef _ZOMBIE_H_
# define _ZOMBIE_H_

# include <iostream>
# include <string>

class Zombie
{
public:
    void announce( void );

    Zombie( std::string name );
    ~Zombie( void );

private:
    std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
void announceZombie( Zombie *zomb);

#endif
