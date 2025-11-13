#pragma once 

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &obj);
        Brain &operator=(const Brain &obj);
        ~Brain();
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index);
};
