#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( Point const & rfs ) : _x(rfs._x), _y(rfs._y)
{
}

Point::Point( Fixed const & x, Fixed const & y ) : _x(x), _y(y)
{
}

Point::Point( int const & x, int const & y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( float const & x, float const & y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( double const & x, double const & y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point( void )
{
}

Point & Point::operator=( Point const & rfs )
{
    return *this;
}

Fixed Point::getX( void ) const
{
    return Fixed(this->_x);
}

Fixed Point::getY( void ) const
{
    return Fixed(this->_y);
}

std::ostream & operator<<( std::ostream & o, Point const & src)
{
    o << "P{" << src.getX() << ", " << src.getY() << "}";
    return o;
}