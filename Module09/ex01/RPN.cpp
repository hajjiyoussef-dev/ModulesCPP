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

    std::stringstream ss(expr);
    std::string token;

    while (ss >> token){

        if (token.size() == 1 && std::isdigit(token[0])){
            _stack.push(token[0] - '0');
        }else if (token == "+" || token == "-" || token == "*" ||
                    token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            long long a = _stack.top();
            _stack.pop();
            long long b = _stack.top();
            _stack.pop();
            long long res;

            if (token == "+")
                res = b + a;
            else if (token == "-")
                res = b - a;
            else if (token == "*")
                res = b * a;
            else {
                if (a == 0)
                    throw std::runtime_error("Error");
                res = b / a;
            }
            _stack.push(res);
        }else {
            throw std::runtime_error("Error");
        }
    }
    
    if (_stack.size() != 1)
            throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;


}



RPN::~RPN() { }