#pragma once

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _dname;
public:
    DiamondTrap( void );
    DiamondTrap( std::string const & name );
    DiamondTrap( DiamondTrap const & other );
    ~DiamondTrap( void );
    DiamondTrap & operator=( DiamondTrap const & other );
    using	ScavTrap::attack;  //  void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void whoAmI( void );
};