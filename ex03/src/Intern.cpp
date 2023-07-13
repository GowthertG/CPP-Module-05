#include "../include/Intern.hpp"
// #include "../include/AForm.hpp"
// #include "../include/ShrubberyCreationForm.hpp"
// #include "../include/PresidentialPardonForm.hpp"
// #include "../include/RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << "default constructer called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "default constructer called" << std::endl;
}

AForm *Intern::SrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::PesidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::RbotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm (target));
}
AForm * Intern::makeForm(std::string name, std::string target)
{
        std::string form_name[3];

    (void)(target);
    form_name[0] = "presidential pardon";
    form_name[1] = "robotomy request";
    form_name[2] = "shrubbery creation";

    AForm *(Intern::* p[])(std::string) = {&Intern::RbotomyRequestForm,
                                           &Intern::SrubberyCreationForm,
                                           &Intern::PesidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == form_name[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*p[i])(target));;
        }
        break;
    }
    return NULL;
}
