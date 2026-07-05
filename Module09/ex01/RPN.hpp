#pragma once 

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
    private:
        std::stack<long long> _stack;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        void calculate(const std::string& expr);
};


