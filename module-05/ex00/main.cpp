#include "Bureaucrat.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &out, Bureaucrat &cat)
{
	out << "Bureaucrat " << cat.getName() << " grade is: " << cat.getGrade();
	return (out);
}

int main()
{
	try
	{
		Bureaucrat cat = Bureaucrat("officer1", 170);
		std::cout << cat << std::endl;
		cat.toIncrease();
		std::cout << "After increase: " << cat << std::endl;
		cat.toDecrease();
		std::cout << "After decrease: " << cat << std::endl;

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
