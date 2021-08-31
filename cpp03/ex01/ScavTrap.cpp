#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    _hitpoints = 100; 
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Default ScavTrap constructor is called" << std::endl;
}

ScavTrap::ScavTrap( std::string const & name ) : ClapTrap(name)
{
    _hitpoints = 100; 
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor is called for " << _name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & other )
{
    std::cout << "Copy ScavTrap constructor is called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap destructor is called for " << _name << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & other )
{
    std::cout << "Assignation operator ScavTrap is called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ScavTrap::attack( std::string const & target )
{
    std::cout << "ScavTrap " << _name << " attack " << target << ", causing ";
    std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage( unsigned int amount )
{
    if (amount < _hitpoints)
        _hitpoints = _hitpoints - amount;
    else
        _hitpoints = 0;
    std::cout << "ScavTrap " << _name << " take " << amount << " damages, and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void ScavTrap::beRepaired( unsigned int amount )
{
    _hitpoints = _hitpoints + amount;
    std::cout << "ScavTrap " << _name << " be repaired on " << amount << ", and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap start Gate keeper mode!" << std::endl;
}