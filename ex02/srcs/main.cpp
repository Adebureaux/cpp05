#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(int ac, char **av)
{
	Bureaucrat b("Kratos", 137);
	ShrubberyCreationForm f("trees");

	b.signForm(f);
	f.execute(b);
	return (0);	
}
