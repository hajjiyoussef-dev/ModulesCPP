
#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called " << std::endl;
    // idea = new std::string("I am a WrongCat");
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj){

    this->type = obj.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj){
    std::cout << "WrongCat copy assignment operator called" <<  std::endl;
    if (this != &obj)
        WrongAnimal::operator=(obj);
    return (*this);
}

void WrongCat::makeSound( void ) const{

    std::cout << "Meow!" << std::endl;
}

WrongCat::~WrongCat(){

    // delete idea;
    std::cout << "WrongCat destructor called" << std::endl;
}