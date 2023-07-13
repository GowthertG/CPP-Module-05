#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    this->target = other.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
     if (this->getSigned() && executor.getGrade() >= this->getGradeToExecute())
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
     else
        throw PresidentialPardonForm::FormNotSigned();
}
// add execute function
