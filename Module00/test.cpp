


#include <iostream>
#include <string>


int main(void){


    std::cout << "hello world" << std::endl ;

    int x;
    int y;
    std::string op;
    std::cout << "Enter ur number" << std::endl ;
    std::cin >> x ;
    std::cout << "Enter the seconde number" << std::endl;
    std::cin >> y ;
    std::cout << "Enter the type of the operation :" ;
    std::cin >> op;
    if (op == "+")
        std::cout << " the result is => " << x + y << std::endl;
    else if (op == "-")
        std::cout << "the result is ==> " << x - y << std::endl; 
    else if (op == "*")
        std::cout << "the result is ==> " << x * y << std::endl;
    else if (op == "/")
        if (y != 0)
            std::cout << "the resut is ==> " << x / y << std::endl;
        else 
            std::cout << "invalid number" << y << std::endl;
    else
        std::cout << "invlid operater " << op << std::endl;

    return (0);
}