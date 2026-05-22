#include "Bureaucrat.hpp"

int main( void )
{

    try
    {
        Bureaucrat a("youssef", 4);
        std::cout << a << std::endl;
        
        // a.decrementGrade();
        a.incrementGrade();
        a.incrementGrade();
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}