#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed z;

    Fixed p1 = ((a.getX() - point.getX()) * (b.getY() - a.getY()) 
            - (b.getX() - a.getX()) * (a.getY() - point.getY()));
    Fixed p2 = ((b.getX() - point.getX()) * (c.getY() - b.getY()) 
            - (c.getX() - b.getX()) * (b.getY() - point.getY()));
    Fixed p3 = ((c.getX() - point.getX()) * (a.getY() - c.getY()) 
            - (a.getX() - c.getX()) * (c.getY() - point.getY()));
    if ((p1 > z && p2 > z && p3 > z) || (p1 < z && p2 < z && p3 < z))
        return true;
    return false; 
}
