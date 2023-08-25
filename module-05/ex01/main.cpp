#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &out, Bureaucrat &cat)
{
	out << "Bureaucrat " << cat.getName() << " grade is: " << cat.getGrade();
	return (out);
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	std::string msg;

	if (form.getSigned())
		msg = " is signed. ";
	else
		msg = " is not signed. ";

	std::cout << "Form: " << form.getName() << msg
		<< " It requires " << form.getRequiredSignGrade() << " grade to sign and "
		<< form.getRequiredExecuteGrade() << " grade to execute. "<< std::endl;

	return (out);
}

int main()
{
	try
	{
		std::cout << "\n\n=====  Bureaucrat =====\n\n";
		Bureaucrat officer1 = Bureaucrat("officer1", 11);
		std::cout << officer1 << std::endl;
		officer1.toIncrease();
		std::cout << "After increase: " << officer1 << std::endl;
		officer1.toDecrease();
		std::cout << "After decrease: " << officer1 << std::endl;

		std::cout << "\n\n=====  Form =====\n\n";
		Form form = Form("Big", 10, 20);
		std::cout << form;

		std::cout << "\n\n=====  sign Form =====\n\n";
		officer1.signForm(form);

		std::cout << "\n\n=====  be signed =====\n\n";
		form.beSigned(officer1);

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

	std::cout << "finished in main!" << std::endl;

	return (0);
}
