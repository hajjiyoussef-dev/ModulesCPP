#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("name"), grade(0) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade){
}

Bureaucrat::~Bureaucrat()
{
}


