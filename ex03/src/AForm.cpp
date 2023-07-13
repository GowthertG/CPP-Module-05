#include "../include/Bureaucrat.hpp"

    AForm::AForm(): name("Default"), Signed(false) , GradeToSign(150), GradeToExecute(150)
    {
        std::cout << "Default AForm constructor called" << std::endl;      
    }

    AForm::AForm(std::string name, int GradeTosign, int GradeToExecute):name(name),GradeToSign(GradeTosign), GradeToExecute(GradeToExecute)
    {
        std::cout << "AForm constructor called" << std::endl;
        this->Signed = false;
        if (GradeTosign > 150 || GradeToExecute > 150)
            throw AForm::GradeTooLowException();
        else if (GradeTosign < 1 || GradeToExecute < 1)
            throw AForm::GradeTooHighException();
    }

    AForm::AForm(const AForm &copy):GradeToSign(copy.GradeToSign), GradeToExecute(copy.GradeToExecute)
    {
        std::cout << "AForm copy constructor called" << std::endl;
        *this = copy;
    }

    AForm::~AForm()
    {
        std::cout << "AForm destructor called" << std::endl;
    }

    const std::string& AForm::getName()const
    {
        return this->name;
    }

    AForm& AForm::operator=(const AForm &copy)
    {
        this->Signed = copy.Signed;
        return *this;
    }

     const bool& AForm::getSigned()const
    {
        return this->Signed;        
    }

    const int& AForm::getGradeToSign()const
    {
        return this->GradeToSign;
    }

    const  int& AForm::getGradeToExecute()const
    {
        return this->GradeToExecute;
    }

    void AForm::beSigned(Bureaucrat &bureaucrat)
    {
        if (this->GradeToSign >= bureaucrat.getGrade())
                this->Signed = true;
        else
            throw AForm::GradeTooLowException();   
    }

    const char* AForm::GradeTooHighException::what() const throw()
    {
        return ("AForm : Grade too high");
    }

    const char* AForm::GradeTooLowException::what() const throw()
    {
        return ("AForm : Grade too low");
    }

    const char*  AForm::FormNotSigned::what() const throw (){
        return ("Form not signed");
    }

    std::ostream& operator<<(std::ostream& os, AForm& AForm)
    {
        std::string SignedOrNot[2];
        SignedOrNot[true] = "is signed";
        SignedOrNot[false] = "is not signed";
        os  << AForm.getName()
            << "'s AForm " 
            << SignedOrNot[AForm.getSigned()]
            << " with grade to sign "
            << AForm.getGradeToSign()
            << " and grade to execute "
            << AForm.getGradeToExecute()
            << std::endl;
        return (os);
    } 

