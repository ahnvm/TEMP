#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Default Intern Constructor Called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(const Intern &other){
	(void)other;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	return *this;
}

AForm *Intern::makeForm(const std::string formName, const std::string target){
	if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	else if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else
		throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw(){
	return "Form not found!";
}

std::ostream &operator<<(std::ostream &os, const Intern &Intern){
	(void)Intern;
	os << "Intern's has the ability to create forms and nothing else.";
	return os;
}