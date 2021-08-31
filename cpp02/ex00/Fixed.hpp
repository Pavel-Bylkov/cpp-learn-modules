#ifndef _FIXED_H_
# define _FIXED_H_

# include <iostream>

class Fixed
{
private:
    int _value;
    static int const _pos_of_bin_point;
public:
    Fixed( void ); // init _value = 0
    Fixed( Fixed const & rfs ); // copy
    ~Fixed( void );
    int getRawBits( void ) const; // returns the raw value of _value
    void setRawBits( int const raw ); // sets the raw value to _value
    Fixed & operator=( Fixed const & rfs ); 
};

#endif
