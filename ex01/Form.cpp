#include "Form.hpp"

Form::Form():_name("Marriage Deal"),_isSigned(false),_signGrade(42),_execGrade(31){
    std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade):_name(name),_isSigned(false), _signGrade(signGrade), _execGrade(execGrade){
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    std::cout << "Form Constructor With Arguments Called" << std::endl;
}

Form::Form(const Form &form):_name(form._name), _isSigned(form._isSigned), _signGrade(form._signGrade), _execGrade(form._execGrade)
{
    std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(const Form &other){
    if (this == &other)
        return *this;
    std::cout << "Form Copy Assignment Operator Called" << std::endl;
    return *this;
}

Form::~Form(){
    std::cout << "Form Destructor Called" << std::endl;
}

const   std::string& Form::getName() const{
    return this->_name;
}

bool    Form::getSignStatus() const{
    return this->_isSigned;
}

int Form::getSignGrade() const{
    return this->_signGrade;
}

int Form::getExecGrade() const{
    return this->_execGrade;
}

void    Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->getSignGrade()){
        std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because grade is too low." << std::endl;
        return ;
    }
    std::cout << bureaucrat.getName() << " is signed " << this->getName() << "." << std::endl;
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form){
    os << form.getName() << "; Sign Grade: " << form.getSignGrade() <<
        " Exec Grade: " << form.getExecGrade() << " Sign Status: " << form.getSignStatus();
    return os;
}