#include "Fixed.hpp"


const int Fixed::fractionBits = 8;


Fixed::Fixed() : number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj){
    std::cout << "Copy constructor called" << std::endl;
    this->number = obj.number;
    
}

Fixed &Fixed::operator=(const Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        number = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed(){
    
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{

    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void Fixed::setRawBits(int const raw){
    number = raw;
}