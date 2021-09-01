#pragma once

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap( void );
    ScavTrap( std::string const & name );
    ScavTrap( ScavTrap const & other );
    ~ScavTrap( void );
    ScavTrap & operator=( ScavTrap const & other );
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void guardGate( void );
};