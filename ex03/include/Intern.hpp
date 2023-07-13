#ifndef INTERN_H
#define INTERN_H
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class Intern :AForm 
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();
    AForm *makeForm(std::string name, std::string target);
    AForm *SrubberyCreationForm(std::string target);
    AForm *PesidentialPardonForm(std::string target);
    AForm *RbotomyRequestForm(std::string target);

};
#endif