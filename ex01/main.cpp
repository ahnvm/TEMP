#include "Form.hpp"

int main(void){
    Bureaucrat b1("Ahmet", 150);
    Bureaucrat b2("Mehmet", 1);

    
    try {
        b1.decrementGrade();
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try {
        b2.incrementGrade();
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try {
        Form form1("Form", 11, 25);
        form1.beSigned(b1);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try {
        Form form1("Form", 11, 25);
        form1.beSigned(b2);
        std::cout << form1 << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}