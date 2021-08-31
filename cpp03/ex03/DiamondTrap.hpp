#pragma once

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
public:
    DiamondTrap( void );
    DiamondTrap( std::string const & name );
    DiamondTrap( DiamondTrap const & other );
    ~DiamondTrap( void );
    DiamondTrap & operator=( DiamondTrap const & other );
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void highFivesGuys( void );
};