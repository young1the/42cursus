#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "# Intern's default constructor called" << std::endl;
}

Intern::Intern(const Intern & other)
{
	std::cout << "# Intern's copy constructor called" << std::endl;
	(void)other;
}

Intern::~Intern()
{
	std::cout << "# Intern's destructor called" << std::endl;
}

Intern& Intern::operator = (const Intern & other)
{
	std::cout << "# Intern's copy assignment operator called" << std::endl;
	(void)other;	
	return *this;
}

Form * Intern::makePresidentialPardonForm(const std::string & target)
{
	return new PresidentialPardonForm(target);
}
Form * Intern::makeRobotomyRequestForm(const std::string & target)
{
	return new RobotomyRequestForm(target);
}
Form * Intern::makeShrubberyCreationForm(const std::string & target)
{
	return new ShrubberyCreationForm(target);
}


Form * Intern::makeForm(const std::string & form_name, const std::string & target)
{
	std::string str;
	for (unsigned long i(0); i < form_name.size(); ++i)
	{
		if (!std::isspace(form_name[i]))
			str.push_back(tolower(form_name[i]));
	}
	std::string forms_name[3] = {"presidentialpardon",
								"robotomyrequest",
								"shrubberycreation"};
	Form *(Intern::*forms_ft[3])(const std::string &) =
	{&Intern::makePresidentialPardonForm,
	&Intern::makeRobotomyRequestForm,
	&Intern::makeShrubberyCreationForm};
	for (int i = 0; i < 3; ++i)
	{
		if (str == forms_name[i])
			return (this->*(forms_ft[i]))(target);
	}
	throw DoesntExistForm();
}

const char * Intern::DoesntExistForm::what() const throw()
{
	return "Form Doesn't Exist!";
}
