#include "ScalarConverter.hpp"


int main(int ac, char **av){

    if (ac != 2){
        std::cout << "the programe shoud have two args" << std::endl;
        return (1);
    }

    ScalarConverter::convert(av[1]);
    return (0);
}