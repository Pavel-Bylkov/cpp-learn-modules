#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
}

ClapTrap::ClapTrap( std::string const & name ) : _name(name), _hitpoints(10), 
                                                _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " was born!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other )
{

}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << _name << " died..." << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & other )
{

}

void ClapTrap::attack( std::string const & target )
{
    std::cout << "ClapTrap " << _name << " attack " << target << ", causing ";
    std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (amount < _energyPoints)
        _energyPoints = _energyPoints - amount;
    else
        _energyPoints = 0;
    std::cout << "ClapTrap " << _name << " take damage " << amount << ", and ";
    std::cout << " energy points is " << _energyPoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    _energyPoints = _energyPoints + amount;
    std::cout << "ClapTrap " << _name << " be repaired on " << amount << ", and ";
    std::cout << " energy points is " << _energyPoints << std::endl;
}
