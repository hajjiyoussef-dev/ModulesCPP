#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called " << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj){

    this->type = obj.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj){
    std::cout << "Cat copy assignment operator called" <<  std::endl;
    if (this != &obj)
        Animal::operator=(obj);
    return (*this);
}

void Cat::makeSound( void ) const{

    std::cout << "Meow!" << std::endl;
}

Cat::~Cat(){

    std::cout << "Cat destructor called" << std::endl;
}