#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{
private:
	const std::string _target;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm);