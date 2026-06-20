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


void Span::addNumber(int number){

    unsigned int size = nbr.size();

    if (size == maximum)
        throw SpanFullException();
    nbr.push_back(number);
}

int Span::shortestSpan(){

    unsigned int size = nbr.size();
    if (size == 1 || size == 0)
        throw std::exception();
    
    std::vector<int> tmp = nbr;
    std::sort(tmp.begin(), tmp.end());
    int shortTest = tmp[1] - tmp[0]; 
    for (unsigned int i = 0; i < tmp.size() - 1; i++){
        int diff =tmp[i + 1] - tmp[i];
        if (diff < shortTest)
            shortTest = diff;
    }
    return (shortTest);
}

int Span::longestSpan(){

    int size = nbr.size();
    if (size == 1 || size == 0)
        throw std::exception();
    int min = *std::min_element(nbr.begin(), nbr.end());
    int max = *std::max_element(nbr.begin(), nbr.end());

    int longest = max - min;
    return (longest);
}


Span::~Span() {}



