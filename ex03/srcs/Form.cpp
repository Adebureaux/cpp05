#include "../includes/Form.hpp"

Form::Form() : name("Undefined"), approved(false), required_approve(100), required_execute(50) {}

Form::Form(const std::string name, int required_approve, int required_execute) : name(name), approved(false), required_approve(setGrade(required_approve)), required_execute(setGrade(required_execute)) {}

Form::Form(const Form &other) : name(other.name), approved(other.approved), required_approve(setGrade(other.required_approve)), required_execute(setGrade(other.required_execute))
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	this->approved = other.approved;
	this->target = other.target;
	return (*this);
}

Form::~Form() {}

std::string Form::getName(void) const
{
	return (this->name);
}

std::string Form::getFormStatus(void) const
{
	return (this->approved ? "signed" : "not signed");
}

int Form::getRequiredApproveGrade(void) const
{
	return (this->required_approve);
}

int Form::getRequiredExecuteGrade(void) const
{
	return (this->required_execute);
}

int Form::setGrade(int grade)
{
	if (grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Form::GradeTooLowException();
	}
	return (grade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->required_approve)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		this->approved = true;
	}
}
bool Form::canExecute(const Bureaucrat &b) const
{
	if (!this->approved)
		throw Form::NotSignedException();
	else if (this->required_execute < b.getGrade())
		throw Form::GradeTooLowException();
	else
		return (true);
	return (false);
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

char const *Form::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream &operator<<(std::ostream &o, Form const &other)
{
	o << "Name                      : " << other.getName() << std::endl
	<< "Status                    : " << other.getFormStatus() << std::endl
	<< "Required grade to approve : " << other.getRequiredApproveGrade() << std::endl
	<< "Required grade to execute : " << other.getRequiredExecuteGrade() << std::endl;
	return (o);
}
