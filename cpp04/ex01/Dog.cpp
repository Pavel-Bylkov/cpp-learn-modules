#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _name("Noname")
{
    cout << "Dog\tdefault constructor called" << endl;
    _brain = new Brain();
    this->addIdea("I am hungry...");
    this->addIdea("I am hungry...");
    this->addIdea("I am hungry...");
}

Dog::Dog( std::string const & name ): Animal("Dog"), _name(name)
{
    cout << "Dog\tconstructor called for " << _name << endl;
    _brain = new Brain();
    this->addIdea("I am hungry...");
    this->addIdea("I am hungry...");
    this->addIdea("I am hungry...");
}

Dog::Dog( Dog const & other )
{
    cout << "Dog\tcopy constructor called" << endl;
    this->_type = other._type;
    this->_name = other._name;
 
    if (other._brain)
        _brain = new Brain(*(other._brain));
    else
        _brain = 0;
}

Dog::Dog( Dog const *other )
{
    cout << "Dog\tcopy constructor called" << endl;
    this->_type = other->getType();
    this->_name = other->_name;
 
    if (other->_brain)
        _brain = new Brain(*(other->_brain));
    else
        _brain = 0;
}


Dog::~Dog( void )
{
    cout << "Dog\tdestructor called" << endl;
    if (_brain != NULL)
        delete _brain;
}

Dog & Dog::operator=( Dog const & other )
{
    cout << "Dog\tassigment operator called" << endl;
    if (this == &other)
        return *this;
    
    if (_brain != NULL)
        delete _brain;
 
    this->_type = other._type;
    this->_name = other._name;
 
    if (other._brain)
        _brain = new Brain(*(other._brain));
    else
        _brain = 0;
    return *this;
}

Dog & Dog::operator=( Dog & other )
{
    cout << "Dog assigment operator called" << endl;
    if (this == &other)
        return *this;

    if (_brain != NULL)
        delete _brain;
 
    this->_type = other._type;
    this->_name = other._name;
 
    if (other._brain)
        _brain = new Brain(*(other._brain));
    else
        _brain = 0;
    return *this;
}

void Dog::makeSound( void ) const
{
    cout << _type << "\t" << _name << " say GAV GAV" << endl;
}

void Dog::printIdeas( void ) const
{
    if (this->_brain != NULL)
    {
        cout << _type << "\t" << _name << " have Brain! Ideas list:" << endl;
        for (int i = 0; i < this->_brain->testIQ(); i++)
            cout << "\t" << i << "\t" << this->_brain->getIdea(i) << endl;
    }
}

void Dog::addIdea( std::string const & idea )
{
    if (this->_brain != NULL)
        this->_brain->addIdea(idea);
}

std::string const & Dog::getName( void ) const
{
    return this->_name;
}

std::ostream & operator<<( std::ostream & o, Dog const & body)
{
    o << body.getType() << " " << body.getName();
    return o;
}