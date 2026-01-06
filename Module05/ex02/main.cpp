#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void){

    std::cout << "===== VALID CREATION ====="<< std::endl;
    try
    {
        Bureaucrat B("youssef", 2);
        Form f("Tax sign ", 2, 1, true);
        std::cout << B << std::endl;
        std::cout << f << std::endl;

        B.signForm(f);
        std::cout << f << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n===== GRADE TOO LOW TO SIGN =====" << std::endl;
    try
    {
        Bureaucrat B1("amine", 120);
        Form f1("Tax sign", 2, 1, false);

        std::cout << B1 << std::endl;
        std::cout << f1 << std::endl;

        B1.signForm(f1);
        std::cout << f1 << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n===== FORM CONSTRUCTOR EXCEPTION =====" << std::endl;
    
    try
    {
        Form bad("BadForm", 0, 1, false);

        std::cout << bad << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n===== BUREAUCRAT CONSTRUCTOR EXCEPTION =====" << std::endl;
    try
    {
        Bureaucrat BadBura("youssef", 160);
        std::cout << BadBura << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}