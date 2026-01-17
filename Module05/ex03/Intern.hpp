#pragma once 


#include <iostream>
#include "AForm.hpp"

class Intern
{

    public:
        Intern();
        Intern(const Intern &obj);
        Intern& operator=(const Intern &obj);
        AForm * makeForm(const std::string& formName, const std::string &target) const;
        ~Intern();

        class FormNotFoundException : public std::exception
        {
            public: 
                const char * what() const throw();
        };
};


