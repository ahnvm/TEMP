#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	const std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm);
