#pragma once


#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & e) const ;
};


