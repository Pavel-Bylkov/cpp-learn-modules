#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    // Animal j;
    // std::cout << j.getType() << std::endl;
    
    Dog some("Sharik");
    {
        Dog tmp1 = some;
        std::cout << tmp1 << std::endl;
        tmp1.printIdeas();
    }
    {
        Dog tmp2(some); 
        std::cout << tmp2 << std::endl;
        tmp2.printIdeas();
    }
    std::cout << some << std::endl;
    some.printIdeas();

    return 0;
}