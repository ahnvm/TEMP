#pragma once

#include "Bureaucrat.hpp"

class AForm{
private:
    const   std::string _name;
    bool                _isSigned;
    const   int			_signGrade;
	const	int			_execGrade;
public:
    AForm();
    virtual ~AForm();
	AForm(const std::string name, const int signGrade, const int execGrade);
	AForm(const AForm& other);
	AForm &operator=(const AForm &other);

	const	std::string	&getName() const;
	bool			getSignStatus() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

	void			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(const Bureaucrat &executor) const = 0;			

	class GradeTooHighException : public std::exception{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char*	what() const throw();
	};
	class FormNotSignedException : public std::exception{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);
