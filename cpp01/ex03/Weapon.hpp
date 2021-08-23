#ifndef _WEAPON_H_
# define _WEAPON_H_

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string const & type);
	~Weapon( void );
	std::string const & getType( void ) const;
	void setType( std::string const & type );
};

#endif
