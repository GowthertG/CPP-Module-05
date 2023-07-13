#ifndef RRFORM_HPP
#define RRFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const &executor) const;
};
#endif