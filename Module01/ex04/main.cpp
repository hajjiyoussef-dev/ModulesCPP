#include <iostream>
#include <fstream>

int main(int ac, char **av){


    if (ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    
    std::string  filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty." << std::endl;
        return (1);
    }
    std::ifstream inputfile;
    inputfile.open(filename.c_str());

    if (!inputfile.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl ;
        return (1);
    }

    std::string line;
    std::getline(inputfile, line, '\0');
    std::size_t index = 0;
    while ((index = line.find(s1, index) ) != std::string::npos)
    {
        line.erase(index, s1.length());
        line.insert(index, s2);
        index += s2.length();
    }

    std::ofstream outfile;
    outfile.open((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return (1);
    }
    outfile << line;
    outfile.close();
    inputfile.close();
    return (0);
}