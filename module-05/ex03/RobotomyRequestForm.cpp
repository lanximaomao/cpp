#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45)
, _target(target)
{
	//
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm("RobotomyRequestForm", other.getRequiredSignGrade(), other.getRequiredExecuteGrade())
{
	//
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "* LOUD DRINLLING NOISE *" << std::endl;
	srand(time(NULL));
	int random_value = rand();
	if (random_value % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
