#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj), target(obj.target){

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){

    if(this != &obj){
        AForm::operator=(obj);
        this->target = obj.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& e) const{


}

ShrubberyCreationForm::~ShrubberyCreationForm(){

    std::cout << "test" << std::endl;
}