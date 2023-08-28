#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		const std::string			_name;
		int							_grade;
		Bureaucrat();

	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~ Bureaucrat();
		void		toIncrease();
		void		toDecrease();

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

		int			getGrade() const;
		std::string	getName() const;

		void signForm(AForm& form);
		void executeForm(AForm& form) const;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif

