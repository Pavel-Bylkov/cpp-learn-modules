#pragma once

# include <iostream>
# include <string>

class Animal
{
protected:
    std::string _type;
public:
    Animal( void );
    Animal( std::string const & type );
    Animal( Animal const & other );
    virtual ~Animal( void );
    Animal & operator=( Animal const & other );
    std::string const & getType( void ) const;
    virtual void makeSound( void ) const;
};