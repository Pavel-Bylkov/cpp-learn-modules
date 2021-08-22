#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

Zombie::Zombie( std::string name ) : _name(name)
{
    return;
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << " died..." << std::endl;
    return;
}

void Zombie::set_name ( std::string name )
{
    this->_name = name;
}