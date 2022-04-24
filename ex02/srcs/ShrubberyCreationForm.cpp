#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery creation", 145, 137), target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery creation", 145, 137),  target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->target = other.target;
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
	std::ofstream file(str);
	file << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n\n\n";
	file << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n\n\n";
	file << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n";
	file.close();
}
