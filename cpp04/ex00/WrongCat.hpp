#pragma once

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:
    std::string _name;
public:
    WrongCat( void );
    WrongCat( std::string const & name );
    WrongCat( WrongCat const & other );
    ~WrongCat( void );
    WrongCat & operator=( WrongCat const & other );
    void makeSound( void ) const;
};