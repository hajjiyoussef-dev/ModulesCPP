#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>



int main(void){

    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);
    vec.push_back(30);
    vec.push_back(35);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::deque<int> deq;

    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}