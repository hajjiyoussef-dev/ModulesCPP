#pragma once 

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
        void execute(Bureaucrat const& e) const;
        static AForm * create(const std::string& target);
        ~RobotomyRequestForm();
};


