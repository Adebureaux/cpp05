#include "../includes/Form.hpp"

Form::Form() : name("Undefined form"), approved(false), required_approve(100), required_execute(10) {}

Form::Form(const Form &other) : name("Undefined form"), required_approve(100), required_execute(10)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	this->approved = other.approved;
	return (*this);
}

Form::~Form()
{

}
