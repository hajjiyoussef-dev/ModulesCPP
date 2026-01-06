#pragma once 

#include <iostream>

class Bureaucrat ;

class Form
{
    private:
        const std::string name ;
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;
    public:
        Form(const std::string name, const int gradeToSign, const int gradeToExecute, bool isSigned);
        Form(const Form &obj);
        Form& operator=(const Form &obj);
        ~Form();
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        
        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception{
            public:
                const char * what() const throw();
        };

        class GradeTooLowException : public std::exception{

            public:
                const char *what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const Form & b);

