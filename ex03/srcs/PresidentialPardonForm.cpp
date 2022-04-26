#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential pardon", 25, 5)
{
	this->target = "undefined";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->canExecute(executor))
		return;
	std::cout << this->target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
