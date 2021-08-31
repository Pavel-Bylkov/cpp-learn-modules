#pragma once

# include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point( void );
    ~Point( void );
    Point( Point const & rfs);
    Point( Fixed const & x, Fixed const & y );
    Point( int const & x, int const & y );
    Point( float const & x, float const & y );
    Point( double const & x, double const & y );
    Point & operator=( Point const & rfs );
    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

std::ostream & operator<<( std::ostream & o, Point const & src);
bool bsp( Point const a, Point const b, Point const c, Point const point);
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y);