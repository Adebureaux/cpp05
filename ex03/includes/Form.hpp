#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	public:
	/* Constructors, operator overload, destructor */
	Form();
	Form(const std::string name, int required_approve, int required_execute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form();

	/* Member functions */
	std::string getName(void) const;
	std::string getFormStatus(void) const;
	int getRequiredApproveGrade(void) const;
	int getRequiredExecuteGrade(void) const;
	int setGrade(int grade);
	void beSigned(const Bureaucrat &b);
	const bool canExecute(const Bureaucrat &b) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

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
	class NotSignedException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	protected:
	std::string target;

	private:
	const std::string	name;
	bool				approved;
	const int			required_approve;
	const int			required_execute;
};

std::ostream &operator<<(std::ostream &o, Form const &other);

#endif
