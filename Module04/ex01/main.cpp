
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"




int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; 
    delete i;
    size_t size =  4;
    Animal * animal[size];

    std::cout << "------------------------------------- 1 "<< std::endl;
    for (size_t i = 0; i < size; i++)
    {
        if (i < i / 2)
            animal[i] = new Dog();
        else 
            animal[i] = new Cat();
    }

    for (size_t i = 0; i < size; i++)
    {
        delete animal[i];
    }
    std::cout << "------------------------------------- 2"<< std::endl;
    
    Dog test1;
    std::cout << &test1 << std::endl;
    std::cout << "copy constructor 1" << std::endl;
    Dog tmp(test1);
    std::cout << &tmp << std::endl;
    std::cout << "copy assignment 2" << std::endl;
    Cat test2;
    std::cout << &test2 << std::endl;
    Cat tmp2;
    tmp2 = test2;
    std::cout << &tmp2 << std::endl;
    std::cout << "------------------------------------- 3"<< std::endl;
    
    return 0;
}
