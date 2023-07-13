#include <iostream>
#include <exception>

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
        const std::string& getName();
        int& getGrade() ;
        void incrementGrade();
        void decrementGrade();

    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public :
           virtual const char* what() const throw();
    };
};
    std::ostream& operator<<(std::ostream& os , Bureaucrat& obj);