#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
private:
	const std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm);