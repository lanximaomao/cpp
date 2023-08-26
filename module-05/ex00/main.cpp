#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bureaucrat = Bureaucrat("officer", 10);
		std::cout << bureaucrat << std::endl;
		bureaucrat.toIncrease();
		std::cout << "After increase: " << bureaucrat << std::endl;
		bureaucrat.toDecrease();
		std::cout << "After decrease: " << bureaucrat << std::endl;

	}
	catch (Bureaucrat::GradeTooHighException &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "finished in main!" << std::endl;

	return (0);
}
