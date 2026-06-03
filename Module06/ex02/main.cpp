#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>


int main(void){

    srand(time(NULL));

    Base *obj = generate();

    identify(obj);
    identify(*obj);
    
    delete obj;
    return (0);
}