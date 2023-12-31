#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_required_signGrade;
		const int			_required_execGrade;
		Form();

	public:

		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException: std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSigned: std::exception
		{
			public:
				const char* what() const throw();
		};

		class AlreadySigned: std::exception
		{
			public:
				const char* what() const throw();
		};

		// member function
		std::string	getName() const;
		bool		getSigned() const;
		int			getRequiredSignGrade() const;
		int			getRequiredExecuteGrade() const;

		void		beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& out, Form& form);

# endif
