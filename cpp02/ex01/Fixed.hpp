#ifndef _FIXED_H_
# define _FIXED_H_

# include <iostream>
# include <bitset>
# include <cmath>

class Fixed
{
private:
    int _value;
    static int const _pos_of_bin_point;
public:
    Fixed( void ); // init _value = 0
    Fixed( int const & n );
    Fixed( float const & n );
    Fixed( Fixed const & rfs ); // copy
    ~Fixed( void );
    int getRawBits( void ) const; // returns the raw value of _value
    void setRawBits( int const raw ); // sets the raw value to _value
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed & operator=( Fixed const & rfs ); 
};

std::ostream & operator<<( std::ostream & o, Fixed const & src);

#endif
