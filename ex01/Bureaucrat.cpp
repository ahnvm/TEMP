#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("John Doe"), _grade(150){
    std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):_name(name), _grade(grade){
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat Constructor With Arguments Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade){
    std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        _grade = other._grade;
    }
    std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor Called" << std::endl;
}

const std::string &Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::incrementGrade(){
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(){
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat){
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}