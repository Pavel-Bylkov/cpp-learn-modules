#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), _name("Noname")
{
    cout << "Cat\tdefault constructor called" << endl;
    _brain = new Brain();
    this->addIdea("I want to sleep...");
    this->addIdea("I want to sleep...");
}

Cat::Cat( std::string const & name ): Animal("Cat"), _name(name)
{
    cout << "Cat\tconstructor called for " << _name << endl;
    _brain = new Brain();
    this->addIdea("I want to sleep...");
    this->addIdea("I want to sleep...");
    this->addIdea("I want to sleep...");
}

Cat::Cat( Cat const & other )
{
    cout << "Cat\tcopy constructor called" << endl;
    this->_type = other._type;
    this->_name = other._name;
 
    if (other._brain)
        _brain = new Brain(*(other._brain));
    else
        _brain = 0;
}

Cat::Cat( Cat const *other )
{
    cout << "Cat\tcopy constructor called" << endl;
    this->_type = other->getType();
    this->_name = other->_name;
 
    if (other->_brain)
        _brain = new Brain(*(other->_brain));
    else
        _brain = 0;
}

Cat::~Cat( void )
{
    cout << "Cat\tdestructor called" << endl;
    if (_brain != NULL)
        delete _brain;
}

Cat & Cat::operator=( Cat const & other )
{
    cout << "Cat\tassigment operator called" << endl;
    if (this == &other)
        return *this;

    delete _brain;
 
    this->_type = other._type;
    this->_name = other._name;
 
    if (other._brain)
        _brain = new Brain(*(other._brain));
    else
        _brain = 0;
    return *this;
}

void Cat::makeSound( void ) const
{
    cout << _type << "\t" << _name << " say MAYU MAYU" << endl;
}

void Cat::printIdeas( void ) const
{
    if (this->_brain)
    {
        cout << _type << "\t" << _name << " have Brain! Ideas list:" << endl;
        for (int i = 0; i < this->_brain->testIQ(); i++)
            cout << "\t" << i << "\t" << this->_brain->getIdea(i) << endl;
    }
}

void Cat::addIdea( std::string const & idea )
{
    if (this->_brain != NULL)
        this->_brain->addIdea(idea);
}

std::string const & Cat::getName( void ) const
{
    return this->_name;
}

std::ostream & operator<<( std::ostream & o, Cat const & body)
{
    o << body.getType() << " " << body.getName();
    return o;
}
