#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequest", 72, 45), _target("default")
{
	std::cout << "# RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
: Form(other), _target(other._target)
{
	std::cout << "# RobotomyRequestForm's copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target_in)
: Form("RobotomyRequest", 72, 45), _target(target_in)
{
	std::cout << "# RobotomyRequestForm's string constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "# RobotomyRequestForm " << getName() << "'s destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm & other)
{
	std::cout << "# RobotomyRequestForm's copy assignment operator called" << std::endl;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSigned())
			throw FormUnsignedException();
		Form::execute(executor);
		std::cout << "... some drilling noises ..." << std::endl;
		std::srand(static_cast<unsigned int>(std::time(0)));
		if (std::rand() % 2 == 0)
			std::cout << _target << ", dead! robotomy failed... X-X" << std::endl;
		else
			std::cout << _target << ", has been robotomized successfully!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << executor.getName() << ", couldn’t execute " << getName()
		<< ", because " << e.what() << std::endl;
	}
}
