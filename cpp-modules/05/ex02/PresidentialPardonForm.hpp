#ifndef PRESIDENTRIALPARDONFORM_HPP
#define PRESIDENTRIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

private:

	std::string _target;

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm & other);
	PresidentialPardonForm(const std::string & target_in);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator = (const PresidentialPardonForm & other);
	/* occf */

	void execute(Bureaucrat const & executor) const;
};

#endif