#pragma once 


#include <iostream>


template <typename T, typename F>

void iter(T* arry, size_t len, F func){

    for (size_t i = 0; i < len; i++)
    {
        func(arry[i]);
    }
    
}
