#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45) {
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj), target(obj.target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){

    if (this != &obj)
    {
        AForm::operator=(obj);
        this->target = obj.target;
    }
    return (*this);
}

void  RobotomyRequestForm::execute(Bureaucrat const &e) const{

    if (!getIsSigned())
        throw FormNotSignedException();
    if (e.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "* Drilling Noises *" << std::endl;
    if(rand() % 2)
        std::cout << target << " has been robotomized successfully " << std::endl;
    else 
        std::cout << "the robotomy failed" << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string & target){

    return new RobotomyRequestForm(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}