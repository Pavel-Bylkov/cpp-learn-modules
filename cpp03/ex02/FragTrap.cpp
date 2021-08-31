#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
    _hitpoints = 100; 
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Default FragTrap constructor is called" << std::endl;
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name)
{
    _hitpoints = 100; 
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor is called for " << _name << std::endl;
}

FragTrap::FragTrap( FragTrap const & other )
{
    std::cout << "Copy FragTrap constructor is called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor is called for " << _name << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & other )
{
    std::cout << "Assignation operator FragTrap is called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void FragTrap::attack( std::string const & target )
{
    std::cout << "FragTrap " << _name << " attack " << target << ", causing ";
    std::cout << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage( unsigned int amount )
{
    if (amount < _hitpoints)
        _hitpoints = _hitpoints - amount;
    else
        _hitpoints = 0;
    std::cout << "FragTrap " << _name << " take " << amount << " damages, and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void FragTrap::beRepaired( unsigned int amount )
{
    _hitpoints = _hitpoints + amount;
    std::cout << "FragTrap " << _name << " be repaired on " << amount << ", and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "I am FragTrap " << _name << ". Give me High Fives!" << std::endl;
}
