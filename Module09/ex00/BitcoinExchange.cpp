#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
        (void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
    (void)obj;
    return (*this);
}


bool BitcoinExchange::validDate(const std::string& date) const{

    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    std::stringstream ss(year);
    std::stringstream ss1(month);
    std::stringstream ss2(day);
    int ye, mo, da;
    if (!(ss >> ye))
        return false;
    if (!(ss1 >>mo))
        return false;
    if (!(ss2 >> da))
        return false;
    if (mo < 1 || mo > 12)
        return false;
    int daysInMouth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((ye % 400 == 0 ) || (ye % 4 == 0 && ye % 100 != 0))
        daysInMouth[1] = 29;
    if (da < 1 || da > daysInMouth[mo - 1])
        return false;
    return true;
}

bool BitcoinExchange::validValue(double value) const {

    if (value < 0 || value > 1000)
        return false;
    return true;
}

double BitcoinExchange::findRate(const std::string& date) const{

    std::map<std::string, double>::const_iterator ite;
    ite = _database.lower_bound(date);

    if (ite == _database.end()){
        --ite;
        return (ite->second);
    }
    if (ite->first == date)
        return ite->second;
    if (ite == _database.begin())
        throw std::runtime_error("Error: no exchange rate available for this date.");
    --ite;
    return ite->second;
}

void BitcoinExchange::loadDatabase(const std::string & filename){

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("data base file not found");
    std::string line;
    
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("data base form error");
    
    std::getline(file, line);
    if (line.empty())
        throw std::runtime_error("data base form error");
    while (!line.empty())
    {
        size_t date_p = line.find(",");
        if (date_p == std::string::npos)
            throw std::runtime_error("Bad database line");
        std::string date = line.substr(0, date_p);
        if (!validDate(date))
            throw std::runtime_error("Error date invalid");
        std::string exchange_rate = line.substr(date_p + 1);
        std::stringstream ss(exchange_rate);
        double rate;
        char extra;
        if (!(ss >> rate) || (ss >> extra))
            throw std::runtime_error("Error invalid rate valuegg");
        _database.insert(std::make_pair(date, rate));
        line = "";
        std::getline(file, line);
    }
}
std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string& filename){

    loadDatabase("data.csv");
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Input file not found");
    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: Empty input file");
    if (line != "date | value")
        throw std::runtime_error("Error: Input form error");
    while (std::getline(file, line))
    {
        try
        {
            size_t date_p = line.find("|");
            if (date_p == std::string::npos){
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            std::string date = trim(line.substr(0, date_p));
            std::string valuestr = trim(line.substr(date_p + 1));
            if (!validDate(date)){
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            std::stringstream ss(valuestr);
            double value;
            char extra;
            
            if (!(ss >> value) || (ss >> extra)){
                throw std::runtime_error("Error: invalid rate values");
            }
            if (!validValue(value)){
                if (value < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else
                    std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            double rate =  findRate(date);
            std::cout << date
                    << " => "
                    << value
                    << " = "
                    << value * rate
                    << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

BitcoinExchange::~BitcoinExchange() {}
