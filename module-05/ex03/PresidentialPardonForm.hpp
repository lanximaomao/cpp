#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	PresidentialPardonForm();
	std::string		_target;

public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	void executeAction() const;
};

# endif
