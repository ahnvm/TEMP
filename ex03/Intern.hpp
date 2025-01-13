#pragma once

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string formName, const std::string target);
	class FormNotFoundException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Intern &Intern);