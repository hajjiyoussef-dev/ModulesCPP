#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj){
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){

    if (this != &obj){
        _vector = obj._vector;
        _list = obj._list;
    }
    return *this;
}

void PmergeMe::parse(char **av){

    for (size_t i = 1; av[i]; i++)
    {
        for (size_t j = 0; av[i][j]; j++)
        {
            if (!std::isdigit(av[i][j]))
                throw std::runtime_error("Error");   
        }

        std::stringstream ss(av[i]);
        long long number;
        if (!(ss >> number))
            throw std::runtime_error("Error");
        if (number > INT_MAX || number < 0)
            throw std::runtime_error("Error");
        _vector.push_back(number);
        _list.push_back(number);
    }
}

void PmergeMe::printBefore(){

    std::cout << "Before: " ;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter(){

    std::cout << "After: " ;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::sorList(){

}


std::vector<int> PmergeMe::sortVector(std::vector<int> v){

    std::vector< std::pair<int, int> > _pairs;
    int struggler;

    if (_vector.size() % 2 != 0)
        struggler = _vector.back();

    for (size_t i = 0; i < _vector.size() - 1; i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            _pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else 
            _pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }

    std::vector<int> win;

    for (size_t i = 0; i < _pairs.size(); i++){
        win.push_back(_pairs[i].second);
    }

    win = sortVector(win)

    // std::cout <<  "sdv sdjvb" <<struggler << std::endl;
    
    
    

}


void PmergeMe::printTime(std::clock_t t1, std::clock_t t2){

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << (static_cast<double>(t1) * 1000000.0) / CLOCKS_PER_SEC << " us " << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << (static_cast<double>(t2) * 1000000.0) / CLOCKS_PER_SEC << " us " << std::endl;
}

PmergeMe::~PmergeMe() {}