#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5){
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj), target(obj.target){

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){

    if (this != &obj){
        AForm::operator=(obj);
        this->target = obj.target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & e) const{

    if (!getIsSigned())
        throw FormNotSignedException();
    if (e.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout   << target 
                << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}