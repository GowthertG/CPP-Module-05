#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this != &copy)
        this->target = copy.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() && executor.getGrade() >= this->getGradeToExecute())
    {
        std::ofstream target;
        target.open(this->target + "_shrubbery");
        if (!target.is_open())
            std::cout << "Error : cannot opening file" << std::endl;
        else
        {

           target << "                                                                                                              ░░░░░░      ░░░░                                                              " << std::endl;
           target << "                                                                                                          ░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒░░                                                              " << std::endl;
           target << "                                                                                ░░    ░░░░░░              ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                          " << std::endl;
           target << "                                                                        ░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░      ░░░░▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░                                                        " << std::endl;
           target << "                                                                    ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                  " << std::endl;
           target << "                                                                  ░░░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒░░                                              " << std::endl;
           target << "                                                                ░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░                                        " << std::endl;
           target << "                                                                ░░▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░                                      " << std::endl;
           target << "                                                        ░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒░░                                      " << std::endl;
           target << "                                                        ▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒░░░░                                  " << std::endl;
           target << "                                                    ░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒░░                                  " << std::endl;
           target << "                                                  ▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓████▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░                                  " << std::endl;
           target << "                                              ░░░░▒▒▒▒▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓████████▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒                                  " << std::endl;
           target << "                                            ░░▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒                                " << std::endl;
           target << "                                          ░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒                                " << std::endl;
           target << "                                          ░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▒▒░░                                " << std::endl;
           target << "                                            ▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒                                " << std::endl;
           target << "                                          ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░                              " << std::endl;
           target << "                                            ▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓██▓▓▓▓████▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░                            " << std::endl;
           target << "                                          ▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓██████████▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓██▓▓▓▓████▓▓▒▒▒▒▓▓░░▓▓▓▓██▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▒▒░░                          " << std::endl;
           target << "                                          ░░░░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░                          " << std::endl;
           target << "                                      ░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░                      " << std::endl;
           target << "                                    ░░▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓██▓▓██▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒░░                      " << std::endl;
           target << "                                    ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒░░                        " << std::endl;
           target << "                                    ▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▒▒░░                    " << std::endl;
           target << "                                    ▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░░░              " << std::endl;
           target << "                                    ▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                " << std::endl;
           target << "                          ░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓████████▓▓██▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓▓▓▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒                  " << std::endl;
           target << "                        ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓████████████▓▓▓▓██████▓▓██████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▒▒▓▓▒▒▒▒▒▒░░          " << std::endl;
           target << "                      ░░▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓████▓▓████▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒          " << std::endl;
           target << "                      ░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓░░          " << std::endl;
           target << "                      ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓░░          " << std::endl;
           target << "                        ▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒░░        " << std::endl;
           target << "                      ░░▒▒▒▒  ░░▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓████████▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒████▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓██▓▓▒▒░░        " << std::endl;
           target << "                                ▒▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓██▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▓▓████▓▓▓▓▓▓████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒          " << std::endl;
           target << "                                ▓▓▓▓▓▓▒▒▒▒▒▒░░░░▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒░░▓▓▒▒▒▒▓▓▒▒▓▓▓▓██▓▓▓▓██▓▓░░░░██▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓  ▒▒▒▒░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒              " << std::endl;
           target << "                                ░░      ▒▒░░  ░░▒▒▓▓▒▒▒▒▒▒░░░░▒▒  ░░▒▒████▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒  ░░▒▒▓▓▓▓░░▒▒██▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓      ░░░░░░░░░░▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒              " << std::endl;
           target << "                                      ░░▒▒░░    ░░▒▒░░    ░░▓▓▒▒░░▒▒▓▓██▓▓▓▓▒▒░░██▒▒▒▒▓▓▓▓▓▓  ░░▓▓▓▓░░▓▓██▒▒▒▒░░▓▓░░  ░░▓▓▒▒          ░░░░    ▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒              " << std::endl;
           target << "                                                                ░░▓▓▓▓▓▓▓▓▒▒░░░░░░▒▒    ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    ▒▒▒▒      ░░              ▒▒░░▒▒▒▒▓▓██▓▓▒▒▓▓▒▒▓▓░░▓▓▓▓▓▓▓▓▒▒▒▒░░              " << std::endl;
           target << "                                                                      ░░░░▒▒                ░░▓▓▓▓▓▓▓▓▓▓░░    ▓▓                        ░░▒▒░░▒▒████░░░░░░▒▒▒▒▓▓░░  ▒▒▒▒▒▒░░                " << std::endl;
           target << "                                                                        ░░░░                    ▓▓▓▓▓▓▓▓    ▓▓▒▒                        ▒▒▓▓▒▒▓▓▒▒▓▓        ▒▒▒▒░░                          " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓░░▓▓▒▒                            ▓▓░░▒▒░░░░          ░░                            " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓▒▒░░                                                                                " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓▒▒                                                                                  " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓░░                                                                                  " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓░░                                                                                  " << std::endl;
           target << "                                                                                                  ▓▓▒▒▓▓▒▒                                                                                  " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓▒▒                                                                                  " << std::endl;
           target << "                                                                                                  ▓▓▓▓▓▓▓▓                                                                                  " << std::endl;
           target << "                                                                                                  ▒▒▓▓▓▓▓▓                                                                                  " << std::endl;
           target << "                                                                                                ░░▒▒▓▓▓▓▓▓                                                                                  " << std::endl;
           target << "                                                                                            ░░▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░░░                                                                            " << std::endl;
           target << "                                                                              ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒▒░░                                                              " << std::endl;
        }
    }
    else
        throw ShrubberyCreationForm::FormNotSigned();
}
// add execute function