#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void){
    AForm *form = new ShrubberyCreationForm("home");
    Bureaucrat bureaucrat("John Doe", 1);
    form->beSigned(bureaucrat);
    bureaucrat.executeForm(*form);
    delete form;
    AForm *form2 = new RobotomyRequestForm("home");
    form2->beSigned(bureaucrat);
    bureaucrat.executeForm(*form2);
    delete form2;
    return 0;
}