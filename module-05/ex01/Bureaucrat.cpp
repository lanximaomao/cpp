#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat:: Bureaucrat():_name("unknown"), _grade(1)
{
	std::cout << "default constructor is called for Bureaucrat " << _name << std::endl;
}

Bureaucrat:: Bureaucrat(const std::string name, const int grade)
: _name(name)
, _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
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

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " grade is: " << bureaucrat.getGrade();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high. ");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low. ");
}

const char* Form::FormNotSigned::what() const throw()
{
	return("Form cannot be executed since it is not signed.");
}

const char* Form::AlreadySigned::what() const throw()
{
	return("Form it is already signed.");
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(Form::AlreadySigned &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
