#pragma once

# include "Animal.hpp"

class Cat : public Animal
{
protected:
    std::string _name;
public:
    Cat( void );
    Cat( std::string const & name );
    Cat( Cat const & other );
    virtual ~Cat( void );
    Cat & operator=( Cat const & other );
    virtual void makeSound( void ) const;
};