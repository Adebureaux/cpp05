#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(int ac, char **av)
{
	Bureaucrat b("Kratos", 1);
	ShrubberyCreationForm f("tree");

	b.signForm(f);
	b.executeForm(f);
	return (0);	
}
