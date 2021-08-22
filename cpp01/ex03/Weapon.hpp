#ifndef _WEAPON_H_
# define _WEAPON_H_

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string _type;
public:
	std::string& getType( void ) const;
	void setType( std::string type );
};

#endif
