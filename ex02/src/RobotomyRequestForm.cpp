#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("RobotomyRequestForm", 72, 45)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    this->target = copy.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
     if (this->getSigned() && executor.getGrade() >= this->getGradeToExecute())
     {
        std::cout << "Vrrrrrrrrrrrrrrrr" << std::endl;
        std::srand(std::time(NULL));
        if (std::rand() % 2)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomization failed" << std::endl;
     }
     else
        throw RobotomyRequestForm::FormNotSigned();
}