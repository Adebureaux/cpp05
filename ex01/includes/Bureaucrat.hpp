#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	public:
	/* Constructors, operator overload, destructor */
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();


	/* Member functions */
	void setGrade(int n);
	void incGrade(void);
	void decGrade(void);
	int getGrade(void) const;
	std::string getName(void) const;

	/* Exeptions class */
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	private:
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other);

#endif
