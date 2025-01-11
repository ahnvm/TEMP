#pragma once

#include "Bureaucrat.hpp"

class Form{
private:
    const   std::string _name;
    bool                _isSigned;
    const   int			_signGrade;
	const	int			_execGrade;
public:
    Form();
    ~Form();
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(const Form& other);
	Form &operator=(const Form &other);

	const	std::string &getName() const;
	bool				getSignStatus() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void				beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
