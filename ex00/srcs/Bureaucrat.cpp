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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->setGrade(other.grade);
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

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

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}
