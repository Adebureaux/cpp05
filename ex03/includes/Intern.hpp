#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	static Form* shrubberyCreation(const std::string target);
	static Form* presidentialPardon(const std::string target);
	static Form* robotomyRequest(const std::string target);
	Form* makeForm(const std::string name, const std::string target);

	private:
	Form* form;
};

#endif
