#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat b1("Ahmet", 31);
    Bureaucrat b2("Umut", 1);

    std::cout << b1 << std::endl;
    b1=b2;
    std::cout << b1 <<std::endl;
    try{
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}