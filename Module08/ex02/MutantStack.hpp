#pragma once 

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& obj);
        MutantStack& operator=(const MutantStack& obj);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator ite;
        ite begin();
        ite end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : std::stack<T>(obj)
{
    
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
    if (this != &obj)
        std::stack<T>::operator=(obj);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::ite MutantStack<T>::begin(){
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::ite MutantStack<T>::end(){
    return (this->c.end());
}



