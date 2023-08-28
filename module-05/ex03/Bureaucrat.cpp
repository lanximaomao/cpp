#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high. ");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low. ");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " grade is: " << bureaucrat.getGrade();
	return (out);
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(AForm::AlreadySigned &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.beExecuted(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::FormNotSigned)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because it is not signed yet" << std::endl;
	}
	catch(Bureaucrat:: GradeTooLowException)
	{
		std::cout << _name << " cannot execute " << form.getName() << " due to its grade is too low" << std::endl;
	}
}
