#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << "\n\n=====  Intern make forms =====\n\n";
		Intern 		someRandomIntern = Intern();
		AForm*		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << "\n\n=====  Bureaucrat =====\n\n";
		Bureaucrat officer = Bureaucrat("officer", 10);

		std::cout << *rrf;

		std::cout << "\n\n=====  sign Form =====\n\n";

		officer.signForm(*rrf);

		std::cout << "\n\n=====  exec Form =====\n\n";
		officer.executeForm(*rrf);

		std::cout << "\n\n=====  clean up =====\n\n";
		delete rrf;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (AForm::FormNotSigned& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch(AForm::AlreadySigned& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "finished in main!" << std::endl;

	return (0);
}
