#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy request", 72, 45)
{
	this->target = "undefined";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->canExecute(executor))
		return;
	std::cout << "*Weird drill noises*" << std::endl;
	std::srand(time(0));
	if (!(std::rand() % 2))
		std::cout << this->target << " has been succesfully robotomised" << std::endl;
	else
		std::cout << "Something went wrong ... " << this->target << " robotomy has failed" << std::endl;
}
