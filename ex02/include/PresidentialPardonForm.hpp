#ifndef PPFORM_HPP
#define PPFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;


};
#endif