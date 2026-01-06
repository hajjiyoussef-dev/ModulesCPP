#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute, bool isSigned) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = isSigned;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &obj): name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) , isSigned(obj.isSigned){}

Form& Form::operator=(const Form &obj){

    if (this != &obj)
        this->isSigned = obj.isSigned;
    return (*this);
}

const std::string Form::getName() const{
    return (name);
}

int Form::getGradeToSign() const{

    return (gradeToSign);
}

int Form::getGradeToExecute() const{

    return (gradeToExecute);
}
bool Form::getIsSigned() const{

    return (isSigned);
}

void Form::beSigned(const Bureaucrat& b){

    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw(){

    return " Grade Too High ";
}

const char * Form::GradeTooLowException::what() const throw(){

    return " Grade Too Low ";
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& b){

    os << b.getName() << " exec grade " << b.getGradeToExecute() << " sign grade " << b.getGradeToSign() << " signed " << ((b.getIsSigned())? "true": "false") ;
    return (os);
}
