#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown"), grade(150) {}

Bureaucrat::Bureaucrat(int grade) : name("Unknown")
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	this->setGrade(other.grade);
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->setGrade(other.grade);
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

void Bureaucrat::setGrade(int grade)
{
	this->grade = grade;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::incGrade(void)
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decGrade(void)
{
	this->setGrade(this->grade + 1);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("bureaucrat grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("bureaucrat grade is too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}
