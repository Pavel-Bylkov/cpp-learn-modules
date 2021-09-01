#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap(), ClapTrap()
{
    _hitpoints = 100; 
    _energyPoints = 50;
    _attackDamage = 30;
    _dname = "Unnamed";
    std::cout << "Default DiamondTrap constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const & name ) : FragTrap(name), ScavTrap(name)
                                                        , ClapTrap(name + "_clap_name")
{
    _hitpoints = 100; 
    _energyPoints = 50;
    _attackDamage = 30;
    _dname = name;
    std::cout << "DiamondTrap constructor is called for " << _dname << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & other ) // : FragTrap(other), ScavTrap(other)
{
    std::cout << "Copy DiamondTrap constructor is called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap destructor is called for " << _dname << std::endl;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & other )
{
    std::cout << "Assignation operator DiamondTrap is called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_dname = other._dname;
        this->_hitpoints = other._hitpoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// void DiamondTrap::attack( std::string const & target )
// {
//     ScavTrap::attack(target);
// }

void DiamondTrap::takeDamage( unsigned int amount )
{
    if (amount < _hitpoints)
        _hitpoints = _hitpoints - amount;
    else
        _hitpoints = 0;
    std::cout << "DiamondTrap " << _dname << " take " << amount << " damages, and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void DiamondTrap::beRepaired( unsigned int amount )
{
    _hitpoints = _hitpoints + amount;
    std::cout << "DiamondTrap " << _dname << " be repaired on " << amount << ", and ";
    std::cout << " hit points is " << _hitpoints << std::endl;
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap name " << _dname << " and ClapTrap name " << _name << std::endl;
}