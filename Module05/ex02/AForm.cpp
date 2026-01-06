#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute, bool isSigned) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = isSigned;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &obj): name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) , isSigned(obj.isSigned){}

AForm& AForm::operator=(const AForm &obj){

    if (this != &obj)
        this->isSigned = obj.isSigned;
    return (*this);
}

const std::string AForm::getName() const{
    return (name);
}

int AForm::getGradeToSign() const{

    return (gradeToSign);
}

int AForm::getGradeToExecute() const{

    return (gradeToExecute);
}
bool AForm::getIsSigned() const{

    return (isSigned);
}

void AForm::beSigned(const Bureaucrat& b){

    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char * AForm::GradeTooHighException::what() const throw(){

    return " Grade Too High ";
}

const char * AForm::GradeTooLowException::what() const throw(){

    return " Grade Too Low ";
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& b){

    os << b.getName() << " exec grade " << b.getGradeToExecute() << " sign grade " << b.getGradeToSign() << " signed " << ((b.getIsSigned())? "true": "false") ;
    return (os);
}
