#include "Point.hpp"

int main( void ) {

    Point const a( Fixed(1), Fixed(1) );
    Point const b( Fixed(10), Fixed(0) );
    Point const c( Fixed(0), Fixed(10) );
    Point const p1( Fixed(2), Fixed(2) );
    Point const p2( Fixed(10), Fixed(0) );
    Point const p3( Fixed(-1), Fixed(4) );
    
    std::cout << "p1(2, 2) in triangl - " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2(10, 0) in triangl - " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3(-1, 4) in triangl - " << bsp(a, b, c, p3) << std::endl;

    std::cout << "p(1, 0) in triangl - " << bsp(Point(0, 1), Point(5.2f, 3.3f), Point(-5.5, -10.7), Point(1, 0)) << std::endl;
    
    return 0;
}