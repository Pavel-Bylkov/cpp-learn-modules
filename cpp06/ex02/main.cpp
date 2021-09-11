#include "Base.hpp"
#include "ABC.hpp"

int main()
{
    std::srand(std::time(NULL)); // initialize random seed

    Base* array[5];

    for (int i = 0; i < 5; i++)
        array[i] = generate();
    std::cout << "------- identify real class with pointer -------" << std::endl;
    for (int i = 0; i < 5; i++)
        identify(array[i]);
    std::cout << "------- identify real class with referens -------" << std::endl;
    for (int i = 0; i < 5; i++)
        identify(*array[i]);

    for (int i = 0; i < 5; i++)
        delete array[i];

    Base test;
    identify(&test);
    identify(test);

    return 0;
}