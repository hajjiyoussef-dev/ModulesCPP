#pragma once


#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{

    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & e) const ;
        static AForm * create(const std::string& target);
};