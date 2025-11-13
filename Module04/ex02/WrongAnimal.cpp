
#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal") {

    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type){

    std::cout << "WrongAnimal copy constructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj){

    if (this != &obj)
        type = obj.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return (*this);
}

void WrongAnimal::makeSound() const{

    std::cout << "Some generic WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    
    return(type);
}

WrongAnimal::~WrongAnimal(){

    std::cout << "WrongAnimal destructor called" << std::endl;
}