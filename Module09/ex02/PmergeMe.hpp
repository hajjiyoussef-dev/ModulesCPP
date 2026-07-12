#pragma once

#include <vector>
#include <iostream>
#include <deque>
#include <sstream>
#include <climits>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        void parse(char **av);
        void printBefore();
        void printAfter();
        void sortV();
        std::vector<int> sortVector(std::vector<int> v);
        std::deque<int> sortDeque(std::deque<int> _deque);
        void sortD();
        void printTime(std::clock_t t1, std::clock_t t2);
        std::vector<size_t> jacobsthalOrder(size_t n);


};



