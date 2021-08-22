#ifndef _ZOMBIE_H_
# define _ZOMBIE_H_

# include <iostream>
# include <string>

class Zombie
{
public:
    void announce( void );

    Zombie( std::string name = "Default_zombie" );
    ~Zombie( void );

    void set_name ( std::string name );

private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
