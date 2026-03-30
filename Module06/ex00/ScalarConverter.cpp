#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

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



void printChar(double value){

    std::cout <<  "char: ";

    if (value != value || value < 0 || value > 127)
        std::cout << "impossible";
    else if (value < 32 || value > 126)
        std::cout << "Non displayable";
    else 
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

void printInt(double value){

    std::cout << "int: ";
    if (value != value || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else 
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}


void printFloat(double value){

    std::cout << "float: ";

    if (value != value)
        std::cout << "nanf";
    else if (value > std::numeric_limits<float>::max())
        std::cout << "+inff" ;
    else if (value < -std::numeric_limits<float>::max())
        std::cout << "-inff";
    else 
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
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
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value);
    std::cout << std::endl;
}


void ScalarConverter::convert(const std::string &value){

    double val;

    if (value.length() == 1 && !std::isdigit(value[0])){
        val = static_cast<double>(value[0]);
    }
    else {

        char *end;
        val = std::strtod(value.c_str(), &end);
        // std::cout << end << "    " << val << std::endl;
        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')){
            
            if (!ispseudoliterals(value)){
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                std::cout << "float: impossible\n";
                std::cout << "double: impossible\n";
                return;
            }
        }        
    }

    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);

}


ScalarConverter::~ScalarConverter(){}