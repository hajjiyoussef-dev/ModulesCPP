

#include "Array.hpp"

int main(void){

    Array<int> arr(5);

    for (size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 2;
    }
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }

    try
    {
        std::cout << arr[10] << std::endl; 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}