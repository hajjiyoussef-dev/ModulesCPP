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

    std::cout << "After: " ;
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;

    if (n == 0)
        return order;

    order.push_back(0);

    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

    std::vector<bool> used(n, false);
    used[0] = true;

    size_t previous = 1;

    for (size_t i = 1; i < jacob.size(); ++i)
    {
        size_t current = std::min(jacob[i], n);

        for (size_t j = current; j > previous; --j)
        {
            if (!used[j - 1])
            {
                order.push_back(j - 1);
                used[j - 1] = true;
            }
        }

        previous = current;
    }

    for (size_t j = n; j > previous; --j)
    {
        if (!used[j - 1])
            order.push_back(j - 1);
    }

    return order;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> v){

    if (v.size() <= 1)
        return v;

    bool hasStruggler = (v.size() % 2 != 0);
    int struggler = 0;
    if (hasStruggler){
        struggler = v.back();
        v.pop_back();
    }

    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] > v[i + 1])
            pairs.push_back(std::make_pair(v[i], v[i + 1])); 
        else
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    largerElements = sortVector(largerElements);

    std::vector< std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j); 
                break;
            }
        }
    }

    std::vector<int> mainChain = largerElements;

    std::vector<size_t> order = jacobsthalOrder(sortedPairs.size());

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        int small = sortedPairs[idx].second;
        int large = sortedPairs[idx].first;

        std::vector<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), large);
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), limit, small);
        mainChain.insert(pos, small);
    }

    if (hasStruggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
        mainChain.insert(pos, struggler);
    }

    return mainChain;
}

void PmergeMe::sortV(){
    _vector = sortVector(_vector);

}



void PmergeMe::printTime(std::clock_t t1, std::clock_t t2){

    double time_v = static_cast<double>(t1) / CLOCKS_PER_SEC * 1000;
    double time_d = static_cast<double>(t2) / CLOCKS_PER_SEC * 1000;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << time_v << " us " << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << time_d << " us " << std::endl;
}



void PmergeMe::sortD(){

    _deque = sortDeque(_deque);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> d){
    if (d.size() <= 1)
        return d;

    bool hasStruggler = (d.size() % 2 != 0);
    int struggler = 0;
    if (hasStruggler){
        struggler = d.back();
        d.pop_back();
    }

    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (d[i] > d[i + 1])
            pairs.push_back(std::make_pair(d[i], d[i + 1])); // first = large, second = small
        else
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
    }

    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largerElements.push_back(pairs[i].first);
    }
    largerElements = sortDeque(largerElements);

    std::deque< std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == largerElements[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::deque<int> mainChain = largerElements;

    std::vector<size_t> order = jacobsthalOrder(sortedPairs.size());

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        int small = sortedPairs[idx].second;
        int large = sortedPairs[idx].first;

        std::deque<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), large);
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), limit, small);
        mainChain.insert(pos, small);
    }

    if (hasStruggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
        mainChain.insert(pos, struggler);
    }

    return mainChain;
}


PmergeMe::~PmergeMe() {}