#pragma once

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
    Fixed( double const & n );
    Fixed( Fixed const & rfs ); // copy
    Fixed( Fixed & rfs ); // copy
    ~Fixed( void );
    int getRawBits( void ) const; // returns the raw value of _value
    void setRawBits( int const raw ); // sets the raw value to _value
    float toFloat( void ) const;
    int toInt( void ) const;
    int toRaw( int const & n ) const;
    int toRaw( float const & n ) const;
    int getPostfix( void ) const;
    Fixed & operator=( Fixed const & rfs ); 
    Fixed & operator=( Fixed & rfs ); 
    Fixed operator+( Fixed const & rfs ) const; 
    Fixed operator-( Fixed const & rfs ) const; 
    Fixed operator*( Fixed const & rfs ) const; 
    Fixed operator/( Fixed const & rfs ) const; 
    Fixed operator+( Fixed & rfs ) const; 
    Fixed operator-( Fixed & rfs ) const; 
    Fixed operator*( Fixed & rfs ) const; 
    Fixed operator/( Fixed & rfs ) const; 
    bool operator>( Fixed const & rfs ) const; 
    bool operator<( Fixed const & rfs ) const; 
    bool operator>=( Fixed const & rfs ) const; 
    bool operator<=( Fixed const & rfs ) const; 
    bool operator==( Fixed const & rfs ) const; 
    bool operator!=( Fixed const & rfs ) const; 
    Fixed & operator++( void );       // Prefix increment operator.
    Fixed operator++( int );     // Postfix increment operator.
    Fixed & operator--( void );       // Prefix decrement operator.
    Fixed operator--( int );     // Postfix decrement operator.
    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed const & min(Fixed const & a, Fixed const & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed const & max(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & src);
