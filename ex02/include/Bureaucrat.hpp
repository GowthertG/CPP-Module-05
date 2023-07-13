#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
#include "../include/AForm.hpp"


class AForm;
class Bureaucrat {

    private:
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade );
        Bureaucrat(Bureaucrat& other);
        ~Bureaucrat();
        
        Bureaucrat& operator=(Bureaucrat& other);
        const std::string& getName() const ;
        const int& getGrade()const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(const AForm & form);

    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public :
           virtual const char* what() const throw();
    };
};
    std::ostream& operator<<(std::ostream& os , const Bureaucrat& obj);
#endif
