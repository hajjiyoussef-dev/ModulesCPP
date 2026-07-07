#pragma once

#include <vector>
#include <iostream>
#include <list>
#include <sstream>
#include <climits>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::list<int> _list;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        void parse(char **av);
        void printBefore();
        void printAfter();
        void sort();
        std::vector<int> sortVector(std::vector<int> v);
        void sorList();
        void printTime(std::clock_t t1, std::clock_t t2);
        std::vector< std::pair<int,int> > makePairs(const std::vector<int>& v);
        std::vector<int> getLargPairs(const std::vector< std::pair<int,int> >& pairs);
        std::vector<int> getSmalPair(const std::vector< std::pair<int,int> >& pairs);
};



