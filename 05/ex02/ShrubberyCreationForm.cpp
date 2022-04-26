#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreation", 145, 137), _target("default")
{
	std::cout << "# ShrubberyCreationForm's default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
: Form(other)
{
	std::cout << "# ShrubberyCreationForm's copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target_in)
: Form("ShrubberyCreation", 145, 137), _target(target_in)
{
	std::cout << "# ShrubberyCreationForm's string constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "# ShrubberyCreationForm " << getName() << "'s destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm & other)
{
	std::cout << "# ShrubberyCreationForm's copy assignment operator called" << std::endl;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSigned())
			throw FormUnsignedException();
	if (getExcuteGrade() < executor.getGrade())
		throw GradeTooLowException();
	std::cout <<executor.getName() << ", excuted "  << getName() << "." << std::endl;
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		std::cout << _target << ", gets Shrubbery" << std::endl;
		plantingTree(_target);
	}
	catch (std::exception & e)
	{
		std::cout << executor.getName() << ", couldn’t execute " << getName()
		<< ", because " << e.what() << std::endl;
	}
}

void ShrubberyCreationForm::plantingTree(const std::string & target) const
{
	std::ofstream f;
	f.open(target + "_shrubbery");
	f <<"                ,@@@@@@@,\n";
	f <<"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	f <<"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	f <<"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	f <<"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	f <<"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	f <<"   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	f <<"       |o|        | |         | |\n";
	f <<"       |.|        | |         | |\n";
	f <<"jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
}


