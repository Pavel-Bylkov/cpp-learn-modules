#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

using std::cout;
using std::endl;

class Cat : public Animal
{
protected:
    std::string _name;
private:
    Brain* _brain;
public:
    Cat( void );
    Cat( std::string const & name );
    Cat( Cat const & other );
    Cat( Cat const *other );
    virtual ~Cat( void );
    Cat & operator=( Cat const & other );
    virtual void makeSound( void ) const;
    virtual void addIdea( std::string const & idea );
    virtual void printIdeas( void ) const;
    std::string const & getName( void ) const;
};

std::ostream & operator<<( std::ostream & o, Cat const & body);