#pragma once 

#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        bool validDate(const std::string& date) const;
        bool validValue(double value) const;
        double findRate(const std::string& date) const;
        std::string trim(const std::string& str) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();
        void loadDatabase(const std::string & filename);
        void processInput(const std::string& filename);

};