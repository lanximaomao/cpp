#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat:: Bureaucrat():_name("unknown"), _grade(1)
{
	std::cout << "default constructor is called for Bureaucrat " << _name << std::endl;
}

Bureaucrat:: Bureaucrat(const std::string name, const int grade)
{
	_name = name;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "parametric constructor is called for Bureaucrat " << _name << std::endl;
}

Bureaucrat:: ~Bureaucrat()
{
	std::cout << "destructor is called for Bureaucrat " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
		*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	return (*this);
}

void		Bureaucrat::toIncrease()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::toDecrease()
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
}


std::string	Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << "bureaucrat " << _name << " couldn't sign " << form.getName()
		<< " because his grade is too low! "<< std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Only grades between the range of 1 and 150 are allowed.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Only grades between the range of 1 and 150 are allowed.");
}
