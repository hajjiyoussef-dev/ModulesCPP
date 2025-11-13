
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"




int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    const WrongAnimal *a = new WrongAnimal();
    const WrongAnimal *a1 = new WrongCat();
    std::cout << a1->getType() << " " << std::endl;
    a1->makeSound();

    delete a;
    delete a1;
    return 0;
}
