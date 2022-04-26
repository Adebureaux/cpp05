#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
class Form;

class Intern
{
	public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	//Form* makeForm(std::string name, std::string target);

	private:
	Form* form;
};

#endif
