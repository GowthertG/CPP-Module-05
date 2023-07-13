#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main ()
{
    // TODO: make  test no test yet and if you find a bug change in ex02 and ex03—
    try{
        Bureaucrat a("houssam", 150);
        Form b("houssam", 150, 120);
        std::cout << b;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}