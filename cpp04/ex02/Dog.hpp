#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

using std::cout;
using std::endl;

class Dog : public Animal
{
protected:
    std::string _name;
private:
    Brain* _brain;
public:
    Dog( void );
    Dog( std::string const & name );
    Dog( Dog const & other );
    Dog( Dog const *other );
    virtual ~Dog( void );
    Dog & operator=( Dog const & other );
    virtual void makeSound( void ) const;
    virtual void printIdeas( void ) const;
    virtual void addIdea( std::string const & idea );
    std::string const & getName( void ) const;
};

std::ostream & operator<<( std::ostream & o, Dog const & body);