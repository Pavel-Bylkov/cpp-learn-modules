#pragma once

template <class T, typename T2>
void iter(T *array, T2 length, void (*const foo)(T&))
{
    for (T2 count = 0; count < length; ++count)
        foo(array[count]);
}

template <class T, typename T2>
void iter(T *array, T2 length, T (*const foo)(T&))
{
    for (T2 count = 0; count < length; ++count)
        array[count] = foo(array[count]);
}