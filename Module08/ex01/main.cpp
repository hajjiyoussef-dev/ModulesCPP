#include "Span.hpp"




int main(void){


    try
    {
        long long n = 10000;
        Span sp = Span(n);
        std::vector<long long> v;
        for (long long i = 0; i < n; i++){
            v.push_back(i);
        }
        sp.addRang(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "--------------------------------------" << std::endl;
    
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   
    return 0;

}