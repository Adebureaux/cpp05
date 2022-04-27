#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Form default_form;
	Form form("Triple copy form", 15, 30);
	try
	{
		Form cpy_construcor(form);
		Form cpy_operator = form;
		std::cout << default_form << std::endl;
		std::cout << form << std::endl;
		std::cout << cpy_construcor << std::endl;
		std::cout << cpy_operator << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "An error occured : " << e.what() << std::endl;
	}

	Bureaucrat philippe("Philippe", 100);
	std::cout << form << std::endl;
	std::cout << form << std::endl;
	philippe.signForm(form);
	std::cout << form << std::endl;

	Form doc("confidential document", 100, 42);
	Form cpy_doc = doc;
	philippe.decGrade();
	std::cout << philippe << std::endl;
	std::cout << doc << std::endl;
	philippe.signForm(doc);
	std::cout << doc << std::endl;;
	philippe.incGrade();
	philippe.signForm(doc);

	try
	{
		std::cout << cpy_doc << std::endl;
		philippe.decGrade();
		cpy_doc.beSigned(philippe);
	}
	catch (const std::exception& e)
	{
		std::cout << "An error occured : " << e.what() << std::endl;
	}
	return (0);	
}
