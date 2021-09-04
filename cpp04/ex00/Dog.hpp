#pragma once

# include "Animal.hpp"

class Dog : public Animal
{
protected:
    std::string _name;
public:
    Dog( void );
    Dog( std::string const & name );
    Dog( Dog const & other );
    virtual ~Dog( void );
    Dog & operator=( Dog const & other );
    virtual void makeSound( void ) const;
};