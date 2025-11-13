
#include "Brain.hpp"


Brain::Brain() {

     std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj){

    std::cout << "Brain copy constructor called " << std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj){

    if (this != &obj){
        for (int i = 0; i < 100; i++){
            this->ideas[i] = obj.ideas[i];
        }
    }
    return (*this);
}

void  Brain::setIdea(int index, const std::string& idea){

    if (index >= 0 && index < 100)
        ideas[index] = idea;
    
}

std::string Brain::getIdea(int index ){

    if (index >= 0 && index < 100)
        return (ideas[index]);
    return "";
}

Brain::~Brain(){

    std::cout << "Brain destructor called" << std::endl;
}
