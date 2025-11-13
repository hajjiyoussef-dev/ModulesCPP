#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called " << std::endl;
    this->type = "cat";
    brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj){

    this->type = obj.type;
    brain = new Brain(*obj.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj){
    std::cout << "Cat copy assignment operator called" <<  std::endl;
    if (this != &obj)
    {
        Animal::operator=(obj);
        *this->brain = *obj.brain;
    }
    return (*this);
}

void Cat::makeSound( void ) const{

    std::cout << "Meow!" << std::endl;
}

Cat::~Cat(){

    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}