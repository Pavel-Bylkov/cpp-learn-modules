#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const Animal* j2 = new Dog("Borbos");
    const Animal* i2 = new Cat("Vas'ka");
    std::cout << j2->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    i2->makeSound(); //will output the cat sound!
    j2->makeSound();

    delete meta;
    delete i;
    delete j;
    delete i2;
    delete j2;

    const WrongAnimal* meta3 = new WrongAnimal();
    const WrongAnimal* i3 = new WrongCat("Vas'ka");
    std::cout << i3->getType() << " " << std::endl;
    i3->makeSound(); //will output the cat sound!
    meta3->makeSound();

    delete meta3;
    delete i3;

    return 0;
}