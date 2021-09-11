#include "serialization.hpp"

int main()
{
    Data test;
    test.symbol = 'X';
    test.number = 42;
    
    uintptr_t save;
    save = serialize(&test);

    Data *res;
    res = deserialize(save);
    std::cout << "result " << res->symbol << " " << res->number << std::endl;

    return 0;
}