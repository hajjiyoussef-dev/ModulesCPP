#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"



int main(void){

    srand(time(NULL));

    std::cout << "===== BUREAUCRATS =====" << std::endl;

    Bureaucrat boss("boss", 1);
    Bureaucrat mid("Mid", 30);
    Bureaucrat low("low", 150);

    std::cout << boss << " " <<  mid << " " << low << std::endl;

    std::cout << "=====  Shrubbery test =====" << std::endl;

    ShrubberyCreationForm shrub("home");

    low.executeForm(shrub);
    low.signForm(shrub);
    mid.signForm(shrub);
    low.executeForm(shrub);
    mid.executeForm(shrub);

    std::cout << "===== Robotomy test =====" << std::endl;

    RobotomyRequestForm robo("amine");

    mid.signForm(robo);
    mid.executeForm(robo);
    mid.executeForm(robo);
    low.signForm(robo);
    low.executeForm(robo);
    low.executeForm(robo);

    std::cout << "===== Presidential test =====" << std::endl;

    PresidentialPardonForm pres("youssef");

    mid.signForm(pres);
    boss.signForm(pres);
    mid.executeForm(pres);
    boss.executeForm(pres);

    std::cout << "===== Intern =====" << std::endl;

    Intern intern;
    Intern intern2;
    Intern intern3;
    AForm* form;
    AForm* form2;
    AForm* form3;

    try {
        form = intern.makeForm("robotomy request", "Bender");
        form2 = intern2.makeForm("shrubbery creation", "Bender");
        form3 = intern3.makeForm("presidential pardon", "Bender");
        delete form;
        delete form2;
        delete form3;
        intern.makeForm("invalid form", "test");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    
    return (0);
    

}