#include "../includes/Bureaucrat.hpp"

int main(int ac, char **av)
{
	// Too high grades
	try
	{
		Bureaucrat("Titin", -1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Cannot construct the bureaucrat Tintin : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat("Milou", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Cannot construct the bureaucrat Milou : " << e.what() << std::endl;
	}

	// Normal grades
	Bureaucrat A("A", 1);
	Bureaucrat("B", 42);
	Bureaucrat("C", 150);
	std::cout << A << std::endl;

	// Too low grades
	try
	{
		Bureaucrat("Dupon", 400);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Cannot construct the bureaucrat Dupon : " << e.what() << std::endl;
	}

	// setGrade
	Bureaucrat test(1);
	try
	{
		test.setGrade(151);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << test << " : " << e.what() << std::endl;
	}

	// Increment grade
	test.setGrade(1);
	try
	{
		test.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << test << " : " << e.what() << std::endl;
	}

	test.setGrade(150);
	try
	{
		test.decGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << test << " : " << e.what() << std::endl;
	}
	return (0);	
}
