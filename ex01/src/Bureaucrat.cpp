#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"), grade(150) {
    std::cout << "Default Constructer called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name , int grade) : name(name)
{
    std::cout << "Constructer called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High !\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too low !\n");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat & copy)
{
    this->grade = copy.grade;
    std::cout << "Assignement operator calledz" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructer called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat & copy) : name(copy.getName())
{
    std::cout << "Copy Constructer called" << std::endl;
    *this = copy;
}

std::ostream& operator<<(std::ostream& os , Bureaucrat& obj)
{
    os << obj.getName() << ", Bureaucrat grade " << obj.getGrade();
    return os;
}

const std::string& Bureaucrat::getName() const
{
    return (this->name);
}

int& Bureaucrat::getGrade()
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form & form)
{    
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << "signed" << form.getName();
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << "couldn’t sign" << form.getName() << " Because grade(" << this->getGrade() << ") is lower than grade to sign(" << form.getGradeToSign() << ")" <<  '\n';
    }
    
}