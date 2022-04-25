#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(int ac, char **av)
{
	{
		Bureaucrat b("Kratos", 137);
		ShrubberyCreationForm f("tree");

		b.signForm(f);
		b.executeForm(f);

		std::cout << std::endl;

		Bureaucrat marvin("Marvin", 45);
		RobotomyRequestForm robot("Marvin");

		marvin.signForm(robot);
		marvin.executeForm(robot);

		std::cout << std::endl;

		Bureaucrat slartibartfast("Slartibartfast", 5);
		PresidentialPardonForm pardon("Slartibartfast");

		slartibartfast.signForm(pardon);
		slartibartfast.executeForm(pardon);
	}

	// Can't execute
	{
		Bureaucrat b("Kratos", 145);
		ShrubberyCreationForm f("tree");

		b.signForm(f);
		b.executeForm(f);

		std::cout << std::endl;

		Bureaucrat marvin("Marvin", 72);
		RobotomyRequestForm robot("Marvin");

		marvin.signForm(robot);
		marvin.executeForm(robot);

		std::cout << std::endl;

		Bureaucrat slartibartfast("Slartibartfast", 25);
		PresidentialPardonForm pardon("Slartibartfast");

		slartibartfast.signForm(pardon);
		slartibartfast.executeForm(pardon);
	}

	// Can't sign
	{
		Bureaucrat b("Kratos", 146);
		ShrubberyCreationForm f("tree");

		b.signForm(f);
		b.executeForm(f);

		std::cout << std::endl;

		Bureaucrat marvin("Marvin", 73);
		RobotomyRequestForm robot("Marvin");

		marvin.signForm(robot);
		marvin.executeForm(robot);

		std::cout << std::endl;

		Bureaucrat slartibartfast("Slartibartfast", 26);
		PresidentialPardonForm pardon("Slartibartfast");

		slartibartfast.signForm(pardon);
		slartibartfast.executeForm(pardon);
	}
	return (0);	
}
