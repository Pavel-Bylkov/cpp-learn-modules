#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    Animal* array[10];
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    const Dog* sharik = new Dog("Borbos");
    const Cat* murzik = new Cat("Vas'ka");

    std::cout << "\n---- start copy loop --------" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << std::endl;
        array[i] = new Dog(sharik);
    }
    for (int i = 5; i < 10; i++)
    {
        std::cout << i << std::endl;
        array[i] = new Cat(murzik);
    }
    std::cout << "\n---- start print and delete loop --------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
        array[i]->printIdeas();
        delete array[i];
    }
    std::cout << "\n---- delete original " << *sharik << "--------" << std::endl;
    delete sharik;
    std::cout << "\n---- delete original " << *murzik << "--------" << std::endl;
    delete murzik;

    std::cout << "\n---- delete j and i --------" << std::endl;
    delete j;//should not create a leak
    delete i;

    std::cout << "\n---- test deep copy 2 " << "--------" << std::endl;
    Dog some;
    {
        Dog tmp1 = some;
        tmp1.printIdeas();
    }
    {
        Dog tmp2(some); 
        tmp2.printIdeas();
    }
    some.printIdeas();

    return 0;
}