#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("no name"), _grade(42)
{
	std::cout << "# Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
: _name(other._name), _grade(other._grade)
{
	std::cout << "# Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name_in, const int & grade_in)
: _name(name_in), _grade(grade_in)
{
	std::cout << "# Bureaucrat's constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		std::cout << "# Bureaucrat " << _name << " construct successly" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "# Bureaucrat " << _name << "'s destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat & other)
{
	std::cout << "# Bureaucrat's copy assignment operator called" << std::endl;
	this->_grade = other._grade;
	return *this;
}

/* occf end */

const std::string & Bureaucrat::getName() const
{
	return _name;
}

const int & Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

std::ostream & operator << (std::ostream & out, const Bureaucrat & bu)
{
	out << bu.getName() << ", bureaucrat grade " << bu.getGrade() << ".";
	return out;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low!";
}
