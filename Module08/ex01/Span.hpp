#pragma once 

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int maximum;
        std::vector<int> nbr;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        ~Span();

        
};



