#include "Form.hpp"

Form::Form()
: _name("unknown")
, _is_signed(false)
, _required_signGrade(1)
, _required_execGrade(1)
{
	std::cout << "default constructor for form " << _name << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade)
: _name(name)
, _is_signed(false)
, _required_signGrade(signGrade)
, _required_execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	std::cout << "parametric constructor for form " << _name << std::endl;
}

Form::~Form()
{
	std::cout << "destructor called for form " << _name << std::endl;
}

Form::Form(const Form& other)
: _name(other._name)
, _is_signed(other._is_signed)
, _required_signGrade(other._required_signGrade)
, _required_execGrade(other._required_execGrade)
{
	std::cout << "copy constructor for form " << _name << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return (*this);
}

std::string Form::getName() const
{
	return(_name);
}

bool Form::getSigned() const
{
	return(_is_signed);
}

int Form::getRequiredSignGrade() const
{
	return(_required_signGrade);
}

int Form::getRequiredExecuteGrade() const
{
	return(_required_execGrade);
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	std::string msg;

	if (form.getSigned())
		msg = " is signed. ";
	else
		msg = " is not signed. ";

	std::cout << "Form: " << form.getName() << msg
		<< " It requires " << form.getRequiredSignGrade() << " grade to sign and "
		<< form.getRequiredExecuteGrade() << " grade to execute. "<< std::endl;

	return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high. ");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low. ");
}

const char* Form::FormNotSigned::what() const throw()
{
	return("Form cannot be executed since it is not signed.");
}

const char* Form::AlreadySigned::what() const throw()
{
	return("Form is already signed.");
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_is_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _required_signGrade)
		throw Bureaucrat::GradeTooLowException();
	_is_signed = true;
	std::cout << "bureaucrat " << bureaucrat.getName() << " signed " << _name << std::endl;
}
