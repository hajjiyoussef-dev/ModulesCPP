#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){

    this->target = target;
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

    if (!getIsSigned())
        throw FormNotSignedException();
    if (e.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::ofstream file((target + "_shrubbery").c_str());
    file << "        *\n";
    file << "       ***\n";
    file << "      *****\n";
    file << "     *******\n";
    file << "    *********\n";
    file << "        |\n";
    file.close();
}

AForm * ShrubberyCreationForm::create(const std::string& target){

    return new ShrubberyCreationForm(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}