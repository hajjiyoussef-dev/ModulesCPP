#pragma once 

#include <iostream>

class Bureaucrat ;

class AForm
{
    protected:
        const std::string name ;
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;
    public:
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &obj);
        AForm& operator=(const AForm &obj);
        virtual ~AForm();
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        
        void beSigned(const Bureaucrat& b);

        virtual void execute(Bureaucrat const & executor) const = 0  ;
        class GradeTooHighException : public std::exception{
            public:
                const char * what() const throw();
        };

        class GradeTooLowException : public std::exception{

            public:
                const char *what() const throw();
        };
        class FormNotSignedException : public std::exception{

            public:
                const char *what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const AForm & b);

