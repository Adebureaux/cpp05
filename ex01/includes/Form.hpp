#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	public:
	/* Constructors, operator overload, destructor */
	Form();
	Form(const std::string name);
	Form(const std::string name, int required_approve, int required_execute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/* Member functions */
	std::string getName(void) const;
	std::string getFormStatus(void) const;
	int getRequiredApproveGrade(void) const;
	int getRequiredExecuteGrade(void) const;
	int setGrade(int grade) const;
	void beSigned(const Bureaucrat &b);

	/* Exeptions class */
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	private:
	const std::string	name;
	bool				approved;
	const int			required_approve;
	const int			required_execute;
};

std::ostream &operator<<(std::ostream &o, Form const &other);

#endif
