#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		std::cout << "\n\n=====  Bureaucrat =====\n\n";
		Bureaucrat officer1 = Bureaucrat("officer1", 10);

		std::cout << "\n\n=====  Form =====\n\n";
		AForm* f1 = new PresidentialPardonForm("Home");
		AForm* f2 = new RobotomyRequestForm("Home");
		AForm* f3 = new ShrubberyCreationForm("Home");

		std::cout << *f1;
		std::cout << *f2;
		std::cout << *f3;

		std::cout << "\n\n=====  sign Form =====\n\n";

		officer1.signForm(*f1);
		//officer1.signForm(*f2);
		//officer1.signForm(*f3);

		std::cout << "\n\n=====  exec Form =====\n\n";
		officer1.executeForm(*f1);
		//officer1.executeForm(*f2);
		//officer1.executeForm(*f3);

		std::cout << "\n\n=====  clean up =====\n\n";
		delete f1;
		delete f2;
		delete f3;
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
