#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

// TODO: make form abstract class

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_required_sign_grade;
		const int			_required_exec_grade;
		Form();

	public:

		Form(const std::string name, const int sign_grade, const int execute_grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// throw(): This part specifies the exception specification.
		// It's a part of the older C++ exception handling mechanism.
		// It indicates that the function will not throw any exceptions itself.
		// In modern C++, this is largely replaced with the noexcept specifier.

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

		// member function
		std::string	getName() const;
		bool		getSigned() const;
		int			getRequiredSignGrade() const;
		int			getRequiredExecuteGrade() const;

		void		beSigned(Bureaucrat &cat);
};

# endif
