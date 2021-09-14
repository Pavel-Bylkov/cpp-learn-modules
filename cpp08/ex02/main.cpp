#include <iostream>
#include <stack>
#include <iterator>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << "add 5 and 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top stack = " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "delete last" << std::endl;
    std::cout << "size = " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "add 3, 5, 737 and 0" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "print all stack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "print pop copy stack" << std::endl;
    // std::iterator<std::input_iterator_tag, int> it = s.begin();
    // std::iterator<std::input_iterator_tag, int> ite = s.end();
    // ++it;
    // --it;
    // std::cout << "print all stack:" << std::endl;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}