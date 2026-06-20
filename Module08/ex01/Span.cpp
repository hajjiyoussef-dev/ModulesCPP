#include "Span.hpp"



Span::Span() {}

Span::Span(unsigned int N) : maximum(N) {

}

Span::Span(const Span& obj){

    *this = obj;
}

Span& Span::operator=(const Span& obj){

    if (this != &obj){
        maximum = obj.maximum;
        nbr = obj.nbr;
    }
    return (*this);
}

Span::~Span() {}



