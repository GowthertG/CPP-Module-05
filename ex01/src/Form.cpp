#include "../include/Bureaucrat.hpp"

    Form::Form(): name("Default"), Signed(false) , GradeToSign(150), GradeToExecute(150)
    {
        std::cout << "Default Form constructor called" << std::endl;      
    }

    Form::Form(std::string name, int GradeTosign, int GradeToExecute):name(name),GradeToSign(GradeTosign), GradeToExecute(GradeToExecute)
    {
        std::cout << "Form constructor called" << std::endl;
        this->Signed = false;
        if (GradeTosign > 150 || GradeToExecute > 150)
            throw Form::GradeTooLowException();
        else if (GradeTosign < 1 || GradeToExecute < 1)
            throw Form::GradeTooHighException();
    }

    Form::Form(Form &copy): name(copy.name),Signed(false), GradeToSign(copy.GradeToSign), GradeToExecute(copy.GradeToExecute)
    {
        std::cout << "Form copy constructor called" << std::endl;

    }

    Form::~Form()
    {
        std::cout << "Form destructor called" << std::endl;
    }

    const std::string& Form::getName() const 
    {
        return this->name;
    }

    Form& Form::operator=(Form &copy)
    {
        this->Signed = copy.Signed;
        return *this;
    }

    bool& Form::getSigned()
    {
        return this->Signed;        
    }

    const int& Form::getGradeToSign()
    {
        return this->GradeToSign;
    }

    const  int& Form::getGradeToExecute()
    {
        return this->GradeToExecute;
    }

    void Form::beSigned(Bureaucrat &bureaucrat)
    {
        if (this->GradeToSign >= bureaucrat.getGrade())
                this->Signed = true;
        else
            throw Form::GradeTooLowException();   
    }

    const char* Form::GradeTooHighException::what() const throw()
    {
        return ("Form : Grade too high");
    }

    const char* Form::GradeTooLowException::what() const throw()
    {
        return ("Form : Grade too low");
    }
    
    std::ostream& operator<<(std::ostream& os, Form& form)
    {
        std::string SignedOrNot[2];
        SignedOrNot[true] = "is signed";
        SignedOrNot[false] = "is not signed";
        os  << form.getName()
            << "'s Form " 
            << SignedOrNot[form.getSigned()]
            << " with grade to sign "
            << form.getGradeToSign()
            << " and grade to execute "
            << form.getGradeToExecute()
            << std::endl;
        return (os);
    } 