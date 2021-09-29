#include <iostream>
#include "mystring.hpp"

using std::cout;

int main()
{
    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"

    cout << hello << std::endl;
    cout << hell << std::endl;
    cout << ell << std::endl;

    String  hello1("hello");
    String  hell1 = hello1[0][4]; // теперь в hell хранится подстрока "hell"
    String  ell1  = hello1[1][4]; // теперь в ell хранится подстрока "ell"
    ell1.append(hello);
    cout << hello1 << std::endl;
    cout << hell1 << std::endl;
    cout << ell1 << std::endl;

    ArrayOfArrays aoa;
    aoa[3][5] = 5;
    cout << aoa[3][5] << std::endl;
    return 0;
}