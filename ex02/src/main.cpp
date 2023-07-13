#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

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