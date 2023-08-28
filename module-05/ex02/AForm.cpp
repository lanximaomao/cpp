#include "AForm.hpp"

AForm::AForm()
: _name("unknown")
, _is_signed(false)
, _required_signGrade(1)
, _required_execGrade(1)
{
	std::cout << "default constructor for Aform " << _name << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
: _name(name)
, _is_signed(false)
, _required_signGrade(signGrade)
, _required_execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
	std::cout << "parametric constructor for Aform " << _name << std::endl;
}

AForm::~AForm()
{
	std::cout << "destructor called for Aform " << _name << std::endl;
}

AForm::AForm(const AForm& other)
: _name(other._name)
, _is_signed(other._is_signed)
, _required_signGrade(other._required_signGrade)
, _required_execGrade(other._required_execGrade)
{
	std::cout << "copy constructor for form " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return(_name);
}

bool AForm::getSigned() const
{
	return(_is_signed);
}

int AForm::getRequiredSignGrade() const
{
	return(_required_signGrade);
}

int AForm::getRequiredExecuteGrade() const
{
	return(_required_execGrade);
}

std::ostream& operator<<(std::ostream& out, AForm& form)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high. ");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low. ");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return("Form cannot be executed since it is not signed.");
}

const char* AForm::AlreadySigned::what() const throw()
{
	return("Form is already signed.");
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_is_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _required_signGrade)
		throw Bureaucrat::GradeTooLowException();
	_is_signed = true;
	std::cout << "bureaucrat " << bureaucrat.getName() << " signed " << _name << std::endl;
}

void	AForm::beExecuted(Bureaucrat const &executor)
{
	if (!getSigned())
		throw FormNotSigned();
	if (getRequiredExecuteGrade() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	executeAction();
}

