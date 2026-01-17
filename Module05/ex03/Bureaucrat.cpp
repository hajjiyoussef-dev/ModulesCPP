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

int Bureaucrat::getGrade() const {
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

void Bureaucrat::signForm(AForm &f){

    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << name << " couldn t sign " << f.getName() << "because" << e.what() << std::endl ;
    }
    
} 

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << " .";
    return os;
}

void  Bureaucrat::executeForm(AForm const&  Form) const {

    try
    {
        Form.execute(*this);
        std::cout << name << " executed " << Form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name <<  " could not execute " << Form.getName() << " because" <<  e.what() << std::endl;
    }
    
}
