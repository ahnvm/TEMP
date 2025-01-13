#include "Intern.hpp"

int main(void){
    Intern intern;
    Bureaucrat bureaucrat("John Doe", 31);
    AForm *form = intern.makeForm("presidential pardon", "home");
    form->beSigned(bureaucrat);
    bureaucrat.executeForm(*form);
    delete form;
    AForm *form2 = intern.makeForm("robotomy request", "home");
    form2->beSigned(bureaucrat);
    bureaucrat.executeForm(*form2);
    delete form2;
    AForm *form3 = intern.makeForm("shrubbery creation", "home");
    form3->beSigned(bureaucrat);
    bureaucrat.executeForm(*form3);
    delete form3;
    return 0;
}