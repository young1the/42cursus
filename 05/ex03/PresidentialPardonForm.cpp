#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardon", 25, 5), _target("default")
{
	std::cout << "# PresidentialPardonForm's default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
: Form(other), _target(other._target)
{
	std::cout << "# PresidentialPardonForm's copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target_in)
: Form("PresidentialPardon", 25, 5), _target(target_in)
{
	std::cout << "# PresidentialPardonForm's string constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "# PresidentialPardonForm " << getName() << "'s destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm & other)
{
	std::cout << "# PresidentialPardonForm's copy assignment operator called" << std::endl;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!getSigned())
			throw FormUnsignedException();
		Form::execute(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << executor.getName() << ", couldn’t execute " << getName()
		<< ", because " << e.what() << std::endl;
	}
}

