#include "iter.hpp"


void printIntConst(int const &x){
    std::cout << x ;
    // std::cout << "\n";
}

void printInt(int &x){
    std::cout << x ;
    
}

int func(int &x){
    x *= 2;
    return x;
}

int main(void){


    int arry[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    iter(arry, 10 , printIntConst);
    iter(arry, 10 , func);
    std::cout << "\n";
    iter(arry, 10 , printInt);
    return 0;
}