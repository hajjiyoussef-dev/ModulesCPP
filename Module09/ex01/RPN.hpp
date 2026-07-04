#pragma once 

#include <stack>
#include <iostream>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        void calculate(const std::string& expr);
};


