#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <string>
#include <sstream>
#include <climits>
#include <cerrno>

ScalarConverter::ScalarConverter(){}


ScalarConverter::ScalarConverter(const ScalarConverter &obj){

    (void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj){

    (void)obj;
    return (*this);
}

static bool ispseudoliterals(const std::string &s){

    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}



void printChar(char value){
    
    std::cout <<  "char: ";
    if (value < 0 || value >= 127)
        std::cout << "impossible";
    else if (value < 32 || value > 126)
        std::cout << "Non displayable";
    else 
        std::cout << "'" << value << "'";
    std::cout << std::endl;
}

void printInt(int value){

    std::cout << "int: ";
    std::cout << value;
    std::cout << std::endl;
}


void printFloat(float value){

    std::cout << "float: ";

    if (value != value)
        std::cout << "nanf";
    else if (value > std::numeric_limits<float>::max())
        std::cout << "+inff" ;
    else if (value < -std::numeric_limits<float>::max())
        std::cout << "-inff";
    else 
        std::cout << std::fixed << std::setprecision(1) << value << "f";
    std::cout << std::endl;
}

void printDouble(double value){

    std::cout << "double: ";

    if (value != value)
        std::cout << "nan";
    else if (value > std::numeric_limits<double>::max())
        std::cout << "+inf";
    else if (value < -std::numeric_limits<double>::max())
        std::cout << "-inf";
    else 
        std::cout << std::fixed << std::setprecision(1) << value;
    std::cout << std::endl;
}


bool isChar(const std::string &s){

    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isInt(const std::string &s){

    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    for (; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool isFloat(const std::string &s){

    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;

    if (s[s.length() - 1] != 'f')
        return false;

    bool dot = false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    for (; i < s.length() - 1; i++)
    {
        if (s[i] == '.')
        {
            if (dot) 
                return false;
            dot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }

    return dot;
}

bool isDouble(const std::string &s){

    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;

    bool dot = false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (dot) 
                return false;
            dot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot;

}


static long parseInt(const std::string &s, bool &ok){

    char *end;
    errno = 0;

    long val = std::strtol(s.c_str(), &end, 10);

    if (*end != '\0' || errno == ERANGE || val > INT_MAX || val < INT_MIN){

        ok = false;
        return (0);
    }
    ok = true;
    return (val); 
}


bool isPseudoFloat(const std::string &s)
{
    return (s == "nanf" || s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string &value)
{
    if (isChar(value)){
        std::cout << "test char " << std::endl;
        char c = value[0];
        
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;

    }else if (isInt(value)){

        std::cout << "test int" << std::endl;
        bool ok;
        long n = parseInt(value, ok);

        if (!ok){
            long double orig = std::strtold(value.c_str(), NULL);
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            printFloat(static_cast<float>(orig));
            printDouble(static_cast<double>(orig));
            return;
        }

        if (n < 0 || n >= 127)
            std::cout << "char: impossible" << std::endl;
        else if (n < 32 || n > 126)
            std::cout << "char: Non displayable" << std::endl;
        else 
            printChar(static_cast<char>(n));
        printInt(n);
        printFloat(static_cast<float>(n));
        printDouble(static_cast<double>(n));
        return;

    }else if (ispseudoliterals(value)){

        if (isPseudoFloat(value)){
            float f = std::atof(value.c_str());
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            printFloat(f);
            printDouble(static_cast<double>(f));
            return;
        }else{
            double d = std::strtod(value.c_str(), NULL);
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            printFloat(static_cast<float>(d));
            printDouble(d);
            return;
        }

    }else if (isFloat(value)){

        std::cout << "test float" << std::endl;
        float f = std::atof(value.c_str());
        printChar(static_cast<char>(f));
        long double orig = std::strtold(value.c_str(), NULL);
        bool is_nan = (orig != orig);
        bool is_finite = (orig == std::numeric_limits<long double>::infinity() || orig == -std::numeric_limits<long double>::infinity());
        if (is_nan || is_finite|| orig > static_cast<long double>(std::numeric_limits<int>::max()) || orig < static_cast<long double>(std::numeric_limits<int>::min()))
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(orig));
        printFloat(f);
        printDouble(static_cast<double>(f));
        return;

    }else if (isDouble(value)){

        std::cout << "test double" << std::endl;

        double d = std::strtod(value.c_str(), NULL);

        printChar(static_cast<char>(d));
        long double orig = std::strtold(value.c_str(), NULL);
        bool is_nan = (orig != orig);
        bool is_finite = (orig == std::numeric_limits<long double>::infinity() || orig == -std::numeric_limits<long double>::infinity());
        if (is_nan || is_finite || orig > static_cast<long double>(std::numeric_limits<int>::max()) || orig < static_cast<long double>(std::numeric_limits<int>::min()))
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(orig));
        printFloat(static_cast<float>(d));
        printDouble(d);
        return;
    }
   
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
    return;

}


ScalarConverter::~ScalarConverter(){}