#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name), grade(obj.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) {

    if (this != &obj)
        this->grade = obj.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return (name);
}

int Bureaucrat::getGrade(){
    return (grade);
}

void Bureaucrat::incrementGrade(){

    if (grade - 1 < 1)
        throw GradeTooHighException() ;
    grade--;
}

void Bureaucrat::decrementGrade(){

    if (grade + 1 > 150)
        throw  GradeTooLowException();
    grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){

    return "Grade Too High ";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){

    return " Grade Too Low" ;
}

