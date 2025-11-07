#include "Fixed.hpp"


const int Fixed::fractionBits = 8;


Fixed::Fixed() : number(0){}

Fixed::Fixed(const Fixed &obj){
    this->number = obj.number;
}

Fixed &Fixed::operator=(const Fixed &obj){
    if (this != &obj)
        number = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed(){}

int Fixed::getRawBits( void ) const{

    return number;
}

void Fixed::setRawBits(int const raw) {

    number = raw;
}

Fixed::Fixed(const int n){

    number = (n << fractionBits );
}


Fixed::Fixed(const float n)
{
    number = roundf(n * (1  << fractionBits));
}

float Fixed::toFloat( void ) const {

    return (float)number / (1 << fractionBits);

}

int Fixed::toInt( void ) const{

    return (number >> fractionBits);
}


std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}

Fixed Fixed::operator*(const Fixed &obj) const {

    return Fixed(this->toFloat() * obj.toFloat());
}


Fixed Fixed::operator+(const Fixed &obj) const{

    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const{

    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const{
    
    return Fixed(this->toFloat() / obj.toFloat());
}

bool Fixed::operator>(const Fixed &obj) const{

    return (number > obj.number);
}

bool Fixed::operator<(const Fixed &obj) const{

    return (number < obj.number);
}

bool Fixed::operator>=(const Fixed &obj) const{

    return (number >= obj.number);
}

bool Fixed::operator<=(const Fixed &obj) const{

    return (number <= obj.number);
}

bool Fixed::operator!=(const Fixed &obj) const{

    return (number != obj.number);
}

bool Fixed::operator==(const Fixed &obj) const{

    return (number == obj.number);
}


Fixed &Fixed::operator++(){
    number++;
    return (*this);
}

Fixed &Fixed::operator--(){
    number--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    number++;
    return (tmp);
}

Fixed Fixed::operator--(int){

    Fixed tmp(*this);
    number--;
    return (tmp);
}



Fixed &Fixed::min(Fixed &a, Fixed &b){

    if (a < b)
        return (a);
    else 
        return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){

    if (a < b)
        return (a);
    else 
        return (b);

}


Fixed &Fixed::max(Fixed &a, Fixed &b){

    if (a > b)
        return (a);
    else 
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){

    if (a > b)
        return (a);
    else 
        return (b);
}