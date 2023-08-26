#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//class Intern
//{
//	private:

//	public:
//		Intern();
//		Intern(const Intern& other);
//		Intern& operator=(const Intern& other);
//		virtual ~Intern();

//		AForm* makeForm(const std::string& name, const std::string& target) const;
//};


Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern() {}

typedef AForm* (Intern::*createNewForm)(const std::string& target) const;

AForm* Intern::makePresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}
AForm* Intern::makeRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}
AForm* Intern::makeShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const
{
	static const int form_count = 3;
	static const std:: string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static const createNewForm func_ptr[] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < form_count; i++)
	{
		if (form == form_names[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (this->*func_ptr[i])(target);
		}
	}
	return (NULL);
}

