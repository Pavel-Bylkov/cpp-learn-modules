#pragma once

# include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hitpoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
public:
    ClapTrap( void );
    ClapTrap( std::string const & name );
    ClapTrap( ClapTrap const & other );
    ~ClapTrap( void );
    ClapTrap & operator=( ClapTrap const & other );
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
};