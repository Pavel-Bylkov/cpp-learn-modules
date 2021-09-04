#pragma once

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal( void );
    WrongAnimal( std::string const & type );
    WrongAnimal( WrongAnimal const & other );
    ~WrongAnimal( void );
    WrongAnimal & operator=( WrongAnimal const & other );
    std::string const & getType( void ) const;
    void makeSound( void ) const;
};