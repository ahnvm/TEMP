#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential Pardon", 25, 5), _target("default"){
	std::cout << "Default PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("Presidential Pardon", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm Constructor With Arguments Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other), _target(other._target){
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	if (!this->getSignStatus()) {
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > this->getExecGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm){
	os << "Presidential Pardon Form " << PresidentialPardonForm.getName() << " is ";
	if (PresidentialPardonForm.getSignStatus())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << PresidentialPardonForm.getSignGrade() << " to sign and grade " << PresidentialPardonForm.getExecGrade() << " to execute";
	return os;
}
