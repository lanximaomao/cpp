#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_required_signGrade;
		const int			_required_execGrade;
		AForm();

	protected:
		virtual void		executeAction() const = 0;

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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
		std::string		getName() const;
		bool			getSigned() const;
		int				getRequiredSignGrade() const;
		int				getRequiredExecuteGrade() const;

		void			beSigned(Bureaucrat &bureaucrat);
		void			beExecuted(Bureaucrat const &executor);
};

std::ostream& operator<<(std::ostream& out, AForm& form);

# endif
