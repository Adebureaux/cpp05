#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Form
{
	public:
	/* Constructors, operator overload, destructor */
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/* Member functions */
	void setRequiredApproveGrade(const int n) const;
	void setRequiredExecuteGrade(const int n) const;
	const int getRequiredApproveGrade(const int n) const;
	const int getRequiredExecuteGrade(const int n) const;
	std::string getName(void) const;

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
