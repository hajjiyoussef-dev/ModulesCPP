#include "RPN.hpp"


RPN::RPN() { }

RPN::RPN(const RPN& obj){
    *this = obj;
}

RPN& RPN::operator=(const RPN& obj){
    
    if (this != &obj)
        _stack = obj._stack;
    return *this;
}

void RPN::calculate(const std::string& expr) {

    


}



RPN::~RPN() { }