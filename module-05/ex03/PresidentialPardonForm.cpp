#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5)
, _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm("PresidentialPardonForm", other.getRequiredSignGrade(), other.getRequiredExecuteGrade())
{
	//
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

