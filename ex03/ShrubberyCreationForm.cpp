#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery Creation", 145, 137), _target("default"){
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):AForm("Shrubbery Creation", 145, 137), _target(target){
	std::cout << "ShrubberyCreationForm Constructor With Arguments Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other), _target(other._target){
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this == &other)
		return *this;
	AForm::operator=(other);
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	if (!this->getSignStatus()) {
		throw AForm::FormNotSignedException();
	}

	if (executor.getGrade() > this->getExecGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open()) {
		throw std::exception();
	}

	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;

	file.close();
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm){
	os << "Shrubbery Creation Form " << ShrubberyCreationForm.getName() << " is ";
	if (ShrubberyCreationForm.getSignStatus())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << ShrubberyCreationForm.getSignGrade() << " to sign and grade " << ShrubberyCreationForm.getExecGrade() << " to execute.";
	return os;
}