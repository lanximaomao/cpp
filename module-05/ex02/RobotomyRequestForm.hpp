#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	RobotomyRequestForm();
	std::string		_target;

public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	void executeAction() const;
};

# endif

