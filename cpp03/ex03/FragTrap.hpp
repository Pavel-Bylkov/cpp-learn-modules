#pragma once

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap( void );
    FragTrap( std::string const & name );
    FragTrap( FragTrap const & other );
    ~FragTrap( void );
    FragTrap & operator=( FragTrap const & other );
    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void highFivesGuys( void );
};