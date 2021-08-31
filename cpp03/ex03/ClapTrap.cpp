#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _name("Unnamed"), _hitpoints(10), 
                            _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default ClapTrap constructor is called" << std::endl;
}

ClapTrap::ClapTrap( std::string const & name ) : _name(name), _hitpoints(10), 
                                                _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor is called for " << _name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other )
{
    std::cout << "Copy ClapTrap constructor is called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap destructor is called for " << _name << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & other )
{
    std::cout << "Assignation operator ClapTrap is called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack( std::string const & target )
{
    std::cout << "ClapTrap " << _name << " attack " << target << ", causing ";
    std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (amount < _hitpoints)
        _hitpoints = _hitpoints - amount;
    else
        _hitpoints = 0;
    std::cout << "ClapTrap " << _name << " take " << amount << " damages, and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    _hitpoints = _hitpoints + amount;
    std::cout << "ClapTrap " << _name << " be repaired on " << amount << ", and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}
