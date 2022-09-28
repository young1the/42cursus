#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <ctime>

class RobotomyRequestForm : public Form {

private:

	std::string _target;

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm & other);
	RobotomyRequestForm(const std::string & target);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator = (const RobotomyRequestForm & other);
	/* occf */

	void execute(Bureaucrat const & executor) const;

};

#endif