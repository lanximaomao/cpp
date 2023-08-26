#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	ShrubberyCreationForm();
	std::string		_target;

public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	void executeAction() const;
};

# endif
