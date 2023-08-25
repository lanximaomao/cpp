#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		std::string			_name;
		int					_grade;
		Bureaucrat();

	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~ Bureaucrat();

		// exception
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
		int			getGrade() const;
		void		toIncrease();
		void		toDecrease();

};

#endif
