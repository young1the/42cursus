#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("no name"), _grade(42)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
: _name(other._name), _grade(other._grade)
{
}

Bureaucrat::Bureaucrat(const std::string & name_in, const int & grade_in)
: _name(name_in), _grade(grade_in)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat & other)
{
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

bool Bureaucrat::operator >(Bureaucrat b)
{
	return (this->getGrade() < b.getGrade()) ? true : false;
}
bool Bureaucrat::operator <(Bureaucrat b)
{
	return (this->getGrade() > b.getGrade()) ? true : false;
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
