#pragma once

# include <iostream>

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitpoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
    ClapTrap( void );
public:
    ClapTrap( std::string const & name );
    ClapTrap( ClapTrap const & other );
    ~ClapTrap( void );
    ClapTrap & operator=( ClapTrap const & other );
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
};