#include "MutantStack.hpp"


int main(void)
{

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Size: " << mstack.size() << std::endl;

    MutantStack<int>::ite it = mstack.begin();
    MutantStack<int>::ite ite = mstack.end();

    std::cout << "Stack contents:" << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return (0);
}