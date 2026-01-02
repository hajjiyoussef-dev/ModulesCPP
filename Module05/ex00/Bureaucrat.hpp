#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat& operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade();
        void incrementGrade();
        void decrementGrade();

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