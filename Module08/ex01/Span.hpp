#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>

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
        void addNumber(int number);

        int shortestSpan();
        int longestSpan();

        class SpanFullException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Span is full";
                }
        };

        class NoSpanException : public std::exception
        {
        public:
                const char *what() const throw()
                {
                    return "Not enough numbers to calculate span";
                }
        };

        
};



