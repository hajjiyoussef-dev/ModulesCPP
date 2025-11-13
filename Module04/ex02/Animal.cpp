
#include "Animal.hpp"

Animal::Animal() : type("Animal") {

    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) : type(obj.type){

    std::cout << "Animal copy constructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &obj){

    if (this != &obj)
        type = obj.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return (*this);
}


std::string Animal::getType() const {
    
    return(type);
}

Animal::~Animal(){

    std::cout << "Animal destructor called" << std::endl;
}