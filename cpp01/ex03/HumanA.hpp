#ifndef _HUMANA_H_
# define _HUMANA_H_

# include "Weapon.hpp"

class HumanA
{
private:
    Weapon& _weapon;
    std::string _name;
public:
    void attack( void );
    HumanA( std::string const & name, Weapon& weapon);
    ~HumanA( void );
};

#endif