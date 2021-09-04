#pragma once

# include <iostream>

class Brain
{
protected:
    std::string _ideas[100];
    int _count;
public:
    Brain( void );
    Brain( Brain const & other );
    ~Brain( void );
    Brain & operator=( Brain const & other );
    std::string const & getIdea( int const & index ) const;
    void addIdea( std::string const & idea );
    int testIQ( void ) const;
};