#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute, bool isSigned) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &obj): name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign), isSigned(isSigned){}

Form& Form::operator=(const Form &obj){

    if (this != &obj)
        this->isSigned = obj.isSigned;
    return (*this);
}

const std::string Form::getName() const{
    return (name);
}

const int Form::getGradeToSign() const{

    return (gradeToSign);
}

const int Form::getGradeToExecute() const{

    return (gradeToExecute);
}
bool Form::getIsSigned() const{

    return (isSigned);
}

void Form::beSigned(const Bureaucrat& b){

    if (b.getGrade() > gradeToSign)
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& b){

    os << b.getName() << b.getGradeToExecute() << b.getGradeToSign() << b.getIsSigned() ;
    return (os);
}