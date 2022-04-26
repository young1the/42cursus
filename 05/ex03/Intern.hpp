#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <exception>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

private:

public:

	Intern();
	Intern(const Intern & other);

	~Intern();

	Intern& operator = (const Intern & other);

	/* occf */

	Form * makeForm(const std::string & form_name, const std::string & target);
	
	class DoesntExistForm : public std::exception
	{
		const char * what() const throw();
	};
};

#endif