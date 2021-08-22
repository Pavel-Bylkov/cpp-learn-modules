#include <iostream>
#include <string>

int main( void )
{
    std::string origin = "HI THIS IS BRAIN";
    std::string *stringPTR = &origin;
    std::string& stringREF = origin;

    std::cout << "the address in memory of the string - " << &origin << std::endl;
    std::cout << "the address in memory of the stringPTR - " << stringPTR << std::endl;
    std::cout << "the address in memory of the stringREF - " << &stringREF << std::endl;

    std::cout << "the string by stringPTR - " << *stringPTR << std::endl;
    std::cout << "the string by stringREF - " << stringREF << std::endl;
    
    return 0;
}