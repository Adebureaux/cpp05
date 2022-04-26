#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

int main(int ac, char **av)
{
	{
		Intern  a;
		Form* b = a.makeForm("bad name", "wrong");
		std::cout << b << std::endl;
		delete b;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat brc("Jhon", 45);
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		brc.signForm(*rrf);
		brc.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat brc("Max", 1);
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		std::cout << *rrf;
		brc.signForm(*rrf);
		brc.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat brc("Marvin", 145);
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Marvin");
		std::cout << *rrf;
		brc.signForm(*rrf);
		brc.executeForm(*rrf);
		delete rrf;
	}
	return (0);	
}
