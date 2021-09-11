#pragma once

#include <iostream>

struct Data
{
    char    symbol;
    int     number;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);