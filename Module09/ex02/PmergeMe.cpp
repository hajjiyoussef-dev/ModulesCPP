#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj){
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){

    if (this != &obj){
        _vector = obj._vector;
        _deque = obj._deque;
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
        _deque.push_back(number);
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

    std::cout << "After vector: " ;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After Deque: " ;
    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}




std::vector< std::pair<int,int> > PmergeMe::makePairs(const std::vector<int>& v){

    int struggler;

    std::vector< std::pair<int, int> > _pairs;

    if (v.size() % 2 != 0)
        struggler = v.back();

    for (size_t i = 0; i < v.size() - 1; i += 2)
    {
        if (v[i] < v[i + 1])
            _pairs.push_back(std::make_pair(v[i], v[i + 1]));
        else 
            _pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
    return (_pairs);
}

std::vector<int> PmergeMe::getLargPairs(const std::vector< std::pair<int,int> >& pairs){

    std::vector<int> win;

    for (size_t i = 0; i < pairs.size(); i++){
        win.push_back(pairs[i].second);
    }
    return (win);
}


std::vector<int> PmergeMe::getSmalPair(const std::vector< std::pair<int,int> >& pairs){

    std::vector<int> win;

    for (size_t i = 0; i < pairs.size(); i++){
        win.push_back(pairs[i].first);
    }
    return (win);
}
void PmergeMe::insertSmall(std::vector<int> &largPairs, std::vector< std::pair<int,int> > &pairs){

    for (size_t i = 0; i < pairs.size(); i++)
    {
        int small = pairs[i].first;
        int partner = pairs[i].second;

        std::vector<int>::iterator limit = std::find(largPairs.begin(), largPairs.end(), partner);
        std::vector<int>::iterator pos =  std::lower_bound(largPairs.begin(), limit + 1, small);
        largPairs.insert(pos, small);
    }
    
}

void PmergeMe::insertStruggler(std::vector<int> &largPairs, int struggler){

    std::vector<int>::iterator pos = std::lower_bound(largPairs.begin(), largPairs.end(), struggler);
    largPairs.insert(pos, struggler);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> v){

    if (v.size() <= 1)
        return (v);

    bool hasStruggler = (v.size() % 2 != 0);
    int struggler = 0;
    
    if (hasStruggler){
        struggler = v.back();
        v.pop_back();
    }
    std::vector< std::pair<int, int> > _pairs = makePairs(v);
    
    std::vector< int > largPairs = getLargPairs(_pairs);


    largPairs = sortVector(largPairs);

    insertSmall(largPairs, _pairs);
    if (hasStruggler)
        insertStruggler(largPairs, struggler);

    return (largPairs);
}

void PmergeMe::sortV(){

    _vector = sortVector(_vector);
}


void PmergeMe::printTime(std::clock_t t1, std::clock_t t2){

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << (static_cast<double>(t1) * 1000000.0) / CLOCKS_PER_SEC << " us " << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::list: " << (static_cast<double>(t2) * 1000000.0) / CLOCKS_PER_SEC << " us " << std::endl;
}



void PmergeMe::sortD(){

    _deque = sorDeque(_deque);
}

std::deque< std::pair<int,int> > PmergeMe::makePairs_D(const std::deque<int>& d){

    int struggler;

    std::deque< std::pair<int, int> > _pairs;

    if (d.size() % 2 != 0)
        struggler = d.back();

    for (size_t i = 0; i < d.size() - 1; i += 2)
    {
        if (d[i] < d[i + 1])
            _pairs.push_back(std::make_pair(d[i], d[i + 1]));
        else 
            _pairs.push_back(std::make_pair(d[i + 1], d[i]));
    }
    return (_pairs);
}

std::deque<int> PmergeMe::getLargPairs_D(const std::deque< std::pair<int,int> >& pairs){

    std::deque<int> win;

    for (size_t i = 0; i < pairs.size(); i++){
        win.push_back(pairs[i].second);
    }
    return (win);
}



void PmergeMe::insertSmall_D(std::deque<int> &largPairs, std::deque< std::pair<int,int> > &pairs){

    for (size_t i = 0; i < pairs.size(); i++)
    {
        int small = pairs[i].first;
        int partner = pairs[i].second;

        std::deque<int>::iterator limit = std::find(largPairs.begin(), largPairs.end(), partner);
        std::deque<int>::iterator pos =  std::lower_bound(largPairs.begin(), limit + 1, small);
        largPairs.insert(pos, small);
    }
    
}

void PmergeMe::insertStruggler_D(std::deque<int> &largPairs, int struggler){

    std::deque<int>::iterator pos = std::lower_bound(largPairs.begin(), largPairs.end(), struggler);
    largPairs.insert(pos, struggler);
}


std::deque<int> PmergeMe::sorDeque(std::deque<int> d){

    if (d.size() <= 1)
        return (d);

    bool hasStruggler = (d.size() % 2 != 0);
    int struggler = 0;
    
    if (hasStruggler){
        struggler = d.back();
        d.pop_back();
    }
    std::deque< std::pair<int, int> > _pairs = makePairs_D(d);
    
    std::deque< int > largPairs = getLargPairs_D(_pairs);

    largPairs = sorDeque(largPairs);

    insertSmall_D(largPairs, _pairs);
    if (hasStruggler)
        insertStruggler_D(largPairs, struggler);
    
    return (largPairs);
}

PmergeMe::~PmergeMe() {}