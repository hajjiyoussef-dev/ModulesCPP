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
        std::deque<int> sorDeque(std::deque<int> _deque);
        void sortD();
        void printTime(std::clock_t t1, std::clock_t t2);
        std::vector< std::pair<int,int> > makePairs(const std::vector<int>& v);
        std::vector<int> getLargPairs(const std::vector< std::pair<int,int> >& pairs);
        std::vector<int> getSmalPair(const std::vector< std::pair<int,int> >& pairs);
        void insertSmall(std::vector<int> &largPairs, std::vector< std::pair<int,int> > &pairs);
        void insertStruggler(std::vector<int> &largPairs, int struggler);

        std::deque< std::pair<int,int> > makePairs_D(const std::deque<int>& d);
        std::deque<int> getLargPairs_D(const std::deque< std::pair<int,int> >& pairs);
        void insertSmall_D(std::deque<int> &largPairs, std::deque< std::pair<int,int> > &pairs);
        void insertStruggler_D(std::deque<int> &largPairs, int struggler);

        std::vector<size_t> jacobsthalOrder(size_t n);



};



