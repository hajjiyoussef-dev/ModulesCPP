#include "Span.hpp"


Span::Span() {}

Span::Span(unsigned int N) : maximum(N) {}

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


void Span::addNumber(long long number){

    unsigned int size = nbr.size();
    if (size == maximum)
        throw SpanFullException();
    nbr.push_back(number);
}


long long Span::shortestSpan(){

    unsigned int size = nbr.size();
    if (size == 1 || size == 0)
        throw NoSpanException();
    
    std::vector<long long> tmp = nbr;
    std::sort(tmp.begin(), tmp.end());
    long long shortTest = tmp[1] - tmp[0]; 
    for (unsigned int i = 0; i < tmp.size() - 1; i++){
        long long  diff = tmp[i + 1] - tmp[i];
        if (diff < shortTest)
            shortTest = diff;
    }
    return (shortTest);
}


long long Span::longestSpan(){

    size_t size = nbr.size();
    if (size == 1 || size == 0)
        throw NoSpanException();
    long long min = *std::min_element(nbr.begin(), nbr.end());
    long long max = *std::max_element(nbr.begin(), nbr.end());

    long long longest = max - min;
    return (longest);
}

Span::~Span() {}

