#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

Form* Intern::shrubberyCreation(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::presidentialPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::robotomyRequest(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* (*fptr[3])(const std::string target) = { Intern::shrubberyCreation, Intern::robotomyRequest, Intern::presidentialPardon };

const std::string type[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

Form* Intern::makeForm(std::string name, const std::string target)
{
	int index = -1;

	for (int i = 0; i < 3; i++)
	{
		if (name == type[i])
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		std::cout << "The form name '" << name << "' doesn't match with our current forms" << std::endl;
		return (NULL);
	}
	return (fptr[index](target));
}
