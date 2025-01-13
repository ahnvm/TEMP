#include "AForm.hpp"

AForm::AForm():_name("Marriage Deal"),_isSigned(false),_signGrade(42),_execGrade(31){
    std::cout << "Default AForm Constructor Called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade):_name(name),_isSigned(false), _signGrade(signGrade), _execGrade(execGrade){
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    std::cout << "AForm Constructor With Arguments Called" << std::endl;
}

AForm::AForm(const AForm &Aform):_name(Aform._name), _isSigned(Aform._isSigned), _signGrade(Aform._signGrade), _execGrade(Aform._execGrade)
{
    std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
    if (this == &other)
        return *this;
    std::cout << "AForm Copy Assignment Operator Called" << std::endl;
    return *this;
}

AForm::~AForm(){
    std::cout << "AForm Destructor Called" << std::endl;
}

const   std::string& AForm::getName() const{
    return this->_name;
}

bool    AForm::getSignStatus() const{
    return this->_isSigned;
}

int AForm::getSignGrade() const{
    return this->_signGrade;
}

int AForm::getExecGrade() const{
    return this->_execGrade;
}

void    AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getSignGrade()){
        throw GradeTooLowException();
    }
    std::cout << bureaucrat.getName() << " is signed " << this->getName() << "." << std::endl;
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform){
    os << Aform.getName() << "; Sign Grade: " << Aform.getSignGrade() <<
        " Exec Grade: " << Aform.getExecGrade() << " Sign Status: " << Aform.getSignStatus();
    return os;
}