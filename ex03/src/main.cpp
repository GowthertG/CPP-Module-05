#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// add the changes that wa2il says to u from ex01 to ex03 (u already did it in ex00 but recompile it)
int main ()
{
    Bureaucrat berau("beru", 137);
    ShrubberyCreationForm form("houssam");
    RobotomyRequestForm form2("Robot");
    try
    {
        berau.signForm(form);
        berau.executeForm(form);
        berau.signForm(form2);
        berau.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
}