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

    return number;
}

void Fixed::setRawBits(int const raw) {

    number = raw;
}

Fixed::Fixed(const int n){

    std::cout << "Int constructor called" << std::endl;
    number = (n << fractionBits );
}


Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    number = roundf(n * (1  << fractionBits));
}

float Fixed::toFloat( void ) const {

    return (float)number / (1 << fractionBits);

}

int Fixed::toInt( void ) const{

    return (number >> fractionBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj){

    out << obj.toFloat();
    return (out);
}