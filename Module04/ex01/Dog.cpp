#include "Dog.hpp"


Dog::Dog() : Animal(){
    
    this->type = "Dog";
    brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj){
    this->type = obj.type;
    std::cout << "Dog copy constructor called" << std::endl;
    brain  = new Brain(*obj.brain);
}

Dog &Dog::operator=(const Dog &obj){

    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &obj){

        Animal::operator=(obj);
        *brain = *obj.brain;
    }
    return (*this);
}

void Dog::makeSound( void ) const {

    std::cout << "Woof!" << std::endl;
}

Dog::~Dog(){
    
    delete brain ;
    std::cout << "Dog destructor called " << std::endl;
}