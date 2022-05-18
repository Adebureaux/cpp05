#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery creation", 145, 137)
{
	this->target = "undefined";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->canExecute(executor))
		return;
	std::string str = this->target;
	str.append("_shrubbery");
	std::ofstream file(str.c_str());
	for (int i = 0; i < 15; i++)
	file << "\n\n\n     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        \\\\////\n         |||/\\\n         |||\\/\n         |||||\n   .....//||||\\....\n\n\n";
	file.close();
}
