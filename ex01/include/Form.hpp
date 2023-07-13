#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private :
        const std::string name;
        bool Signed;
        const int GradeToSign;
        const int GradeToExecute;
   public  :
        Form();
        Form(std::string name, int GradeTosign, int GradeToExecute);
        Form(Form &copy);
        ~Form();
        Form & operator=(Form &copy);
        const std::string& getName();
        bool & getSigned();
        const int & getGradeToSign();
        const  int & getGradeToExecute();
        void beSigned(Bureaucrat &bureaucrat);
        class GradeTooHighException
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException
        {
            virtual const char* what() const throw();
        };
};
std::ostream & operator<<(std::ostream &os, Form &form);

#endif