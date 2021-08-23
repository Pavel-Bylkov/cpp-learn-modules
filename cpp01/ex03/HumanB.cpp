#include "HumanB.hpp"

void HumanB::attack( void )
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
    
HumanB::HumanB( std::string const & name ) : _name(name)
{
    this->_weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->_weapon = &weapon;
}