#pragma once

#include <iostream>

#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat& operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void  executeForm(AForm const & form) const ;
        class GradeTooHighException : public std::exception{

            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{

            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream & os, const Bureaucrat& b);