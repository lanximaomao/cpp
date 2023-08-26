#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "\n\n=====  Bureaucrat =====\n\n";
		Bureaucrat officer = Bureaucrat("officer", 10);

		std::cout << "\n\n=====  Form =====\n\n";
		Form form = Form("Blueprint", 10, 20);
		std::cout << form;

		std::cout << "\n\n=====  sign Form =====\n\n";
		officer.signForm(form);

		std::cout << "\n\n=====  test alreadySign exception =====\n\n";
		//officer.signForm(form);
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Form::AlreadySigned& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "finished in main!" << std::endl;

	return (0);
}
