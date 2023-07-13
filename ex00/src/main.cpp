#include "../include/Bureaucrat.hpp"

int main ()
{
    try
    { 
        // Bureaucrat a("a", 2);
        // std::cout << a.getGrade() << std::endl;
        // std::cout << a.getName() << std::endl;
        // a.incrementGrade();
        // std::cout << a.getGrade() << std::endl;
        // a.decrementGrade();
        // std::cout << a.getGrade() << std::endl;
        // a.incrementGrade();
        // a.incrementGrade();
        // 
        Bureaucrat a("a", 150);
        std::cout << a.getGrade() << std::endl;
        std::cout << a.getName() << std::endl;
        a.incrementGrade();
        std::cout << a.getGrade() << std::endl;
        a.decrementGrade();
        std::cout << a.getGrade() << std::endl;
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}