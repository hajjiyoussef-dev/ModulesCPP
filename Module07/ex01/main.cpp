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

    size_t len  = sizeof(arry) / sizeof(arry[0]);

    iter(arry, len , printIntConst);
    iter(arry, len , func);
    std::cout << "\n";
    iter(arry, len , printInt);
    return 0;
}