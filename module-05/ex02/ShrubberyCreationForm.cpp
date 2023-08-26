#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137)
, _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm("ShrubberyCreationForm", other.getRequiredSignGrade(), other.getRequiredExecuteGrade())
{
	//
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream outputFile;

	try
	{
		outputFile.open(_target + "_shrubbery");
	}
	catch(std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
		return;
	}

	outputFile << "       _-_\n";
	outputFile << "    /~~   ~~\\\n";
	outputFile << " /~~         ~~\\\n";
	outputFile << "{               }\n";
	outputFile << " \\  _-     -_  /\n";
	outputFile << "   ~   \\ //  ~\n";
	outputFile << "_- -   | | _- _\n";
	outputFile << "  _ -  | |   -_\n";
	outputFile << "      // \\";

	outputFile.close();
	std::cout << "* So long, summer! *" << std::endl;
}
