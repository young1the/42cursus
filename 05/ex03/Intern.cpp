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

Form * Intern::makeForm(const std::string & form_name, const std::string & target)
{
	std::string str;
	for (unsigned long i(0); i < form_name.size(); ++i)
	{
		if (!std::isspace(form_name[i]))
			str.push_back(tolower(form_name[i]));
	}
	
	std::string forms[3] = {"presidentialpardon", "robotomyrequest", "shrubberycreation"};
	int i(0);
	while (i < 3)
	{
		if (str == forms[i])
			break ;
		++i;
	}

	Form *ret;
	switch (i)
	{
	case 0:
		ret = new PresidentialPardonForm(target);
		break;
	case 1:
		ret = new RobotomyRequestForm(target);
		break;
	case 2:
		ret = new ShrubberyCreationForm(target);
		break;
	default:
		throw DoesntExistForm();
		break;
	}

	return (ret);
}

const char * Intern::DoesntExistForm::what() const throw()
{
	return "Form Doesn't Exist!";
}
