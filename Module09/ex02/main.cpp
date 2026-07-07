#include "PmergeMe.hpp"


int main(int ac, char **av){

    if (ac == 1)
        return (std::cout << "Error: Enter in input" << std::endl, 1);
    
    try
    {
        PmergeMe pme;
        pme.parse(av);
        pme.printBefore();
        std::clock_t start_time1 = std::clock();
        pme.sort();
        start_time1 = std::clock() - start_time1;
        std::clock_t start_time2 = std::clock();
        pme.sorList();
        start_time2 = std::clock() - start_time2;
        pme.printAfter();
        pme.printTime(start_time1, start_time2);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}