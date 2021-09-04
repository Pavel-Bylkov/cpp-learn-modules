#include "Brain.hpp"

Brain::Brain( void ) : _count(0)
{
    std::cout << "Brain\tdefault constructor called" << std::endl;
}

Brain::Brain( Brain const & other )
{
    std::cout << "Brain\tcopy constructor called" << std::endl;
    *this = other;
}

Brain::~Brain( void )
{
    std::cout << "Brain\tdestructor called" << std::endl;
}
    
Brain & Brain::operator=( Brain const & other )
{
    if (this != &other)
    {
        std::cout << "Brain\toperator= is called" << std::endl;
        this->_count = other._count;
        for (int i = 0; i < this->_count; i++)
            this->_ideas[i] = other._ideas[i].substr();
    }
    return *this;
}

std::string const & Brain::getIdea( int const & index ) const
{
    if (index < this->_count)
        return this->_ideas[index];
    std::cout << "Error: Brain index out of range" << std::endl;
    exit(1);
}

void Brain::addIdea(std::string const & idea )
{
    if (idea != "" and this->_count < 100)
    {
        this->_ideas[_count] = idea.substr();
        this->_count++;
    }
    else if (this->_count == 100)
        std::cout << "Brain is full!" << std::endl;
}

int Brain::testIQ( void ) const
{
    return this->_count;
}