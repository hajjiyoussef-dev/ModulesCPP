

#include "Harl.hpp"

int main(int ac, char **av){

    Harl harl;

    if (ac != 2){
        
        std::cout << "the program must takes as a parameter one of the four levels" << std::endl;
        return (1);
    }
    std::string level = av[1];

    harl.complain(level);
    
}