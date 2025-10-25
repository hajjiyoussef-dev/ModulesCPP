#include "Point.hpp"


int main( void ){

    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);


    Point inside(10, 15);
    Point outside(0, 0);


    std::cout << bsp(a, b, c, inside) << std::endl;
    std::cout << bsp(a, b, c, outside) <<  std::endl;

    return (1);
}