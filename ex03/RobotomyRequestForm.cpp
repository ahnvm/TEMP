#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("Robotomy Request", 72, 45), _target("default"){
	std::cout << "Default RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):AForm("Robotomy Request", 72, 45), _target(target){
	std::cout << "RobotomyRequestForm Constructor With Arguments Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other), _target(other._target){
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	if (!this->getSignStatus()) {
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > this->getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	srand(time(NULL));
	std::cout << "*drilling noises* ";
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm){
	os << "Robotomy Request Form " << RobotomyRequestForm.getName() << " is ";
	if (RobotomyRequestForm.getSignStatus())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << RobotomyRequestForm.getSignGrade() << " to sign and grade " << RobotomyRequestForm.getExecGrade() << " to execute." << std::endl;
	return os;
}
