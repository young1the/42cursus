#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {

private:

	std::string _target;
	void plantingTree(const std::string & target) const;

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm & other);
	ShrubberyCreationForm(const std::string & target);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator = (const ShrubberyCreationForm & other);
	/* occf */

	void execute(Bureaucrat const & executor) const;
};

#endif