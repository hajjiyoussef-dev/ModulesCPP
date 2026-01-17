#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(){}

Intern::Intern(const Intern &){

}

Intern &Intern::operator=(const Intern &){

    return (*this);
}

AForm *Intern::makeForm(const std::string & formName, const std::string & target)const{

    const std::string name[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*form[3])(const std::string&) = {
        &ShrubberyCreationForm::create,
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == name[i])
        {
            std::cout << " Intern creates " << formName << std::endl;
            return form[i](target);
        }
    }
    
    throw FormNotFoundException();
}

const char * Intern::FormNotFoundException::what() const throw() {

    return " Invalid Form Name " ;
}

Intern::~Intern(){}