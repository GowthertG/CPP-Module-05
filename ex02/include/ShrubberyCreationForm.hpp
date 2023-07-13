#ifndef SCFORM_HPP
#define SCFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &) const;
};
#endif