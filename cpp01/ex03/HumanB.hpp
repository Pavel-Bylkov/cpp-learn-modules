#ifndef _HUMANB_H_
# define _HUMANB_H_

# include "Weapon.hpp"

class HumanB
{
private:
    Weapon _weapon;
    std::string _name;
public:
    void attack( void );
    HumanB( std::string name );
    ~HumanB();
    void setWeapon( Weapon& weapon );
};

#endif