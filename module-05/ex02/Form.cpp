#include "Form.hpp"

Form::Form()
: _name("unknown")
, _is_signed(false)
, _required_sign_grade(1)
, _required_exec_grade(1)
{
	std::cout << "default constructor for form " << _name << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
: _name(name)
, _required_sign_grade(sign_grade)
, _required_exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || sign_grade < 1)
		throw GradeTooHighException();
	_is_signed = false;
	std::cout << "parametric constructor for form " << _name << std::endl;
}

Form::~Form()
{
	std::cout << "destructor called for form " << _name << std::endl;
}

Form::Form(const Form& other)
: _name(other._name)
, _is_signed(other._is_signed)
, _required_sign_grade(other._required_sign_grade)
, _required_exec_grade(other._required_exec_grade)
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
	return(_required_sign_grade);
}

int Form::getRequiredExecuteGrade() const
{
	return(_required_exec_grade);
}

void Form::beSigned(Bureaucrat &cat)
{
	if (cat.getGrade() <= _required_sign_grade)
	{
		_is_signed = 1;
		std::cout << "bureaucrat " << cat.getName() << " signed " << _name << std::endl;
	}
	else
	{
		_is_signed = 0;
		std::cout << "bureaucrat " << cat.getName() << " cann't sign " << _name << std::endl;
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Only grades between the range of 1 and 150 are allowed.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Only grades between the range of 1 and 150 are allowed.");
}
