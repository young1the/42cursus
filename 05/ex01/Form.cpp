#include "Form.hpp"

Form::Form()
: _name("no name"), _is_signed(false), _sign_grade(42), _excute_grade(42)
{
	std::cout << "# Form's default constructor called" << std::endl;
}

Form::Form(const Form & other)
: _name(other._name),
_is_signed(other._is_signed),
_sign_grade(other._sign_grade),
_excute_grade(other._excute_grade)
{
	std::cout << "# Form's copy constructor called" << std::endl;
}

Form::Form(const std::string & name_in, const int & sign_grade_in, const int & excute_grade_in)
: _name(name_in),
_is_signed(false),
_sign_grade(sign_grade_in),
_excute_grade(excute_grade_in)
{
	std::cout << "# Form's constructor called" << std::endl;
	if (_sign_grade < 1 || _excute_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _excute_grade > 150)
		throw GradeTooLowException();
	else
		std::cout << "# Form " << _name << " construct successly" << std::endl;
}

Form::~Form()
{
	std::cout << "# Form " << _name << "'s destructor called" << std::endl;
}

Form& Form::operator = (const Form & other)
{
	std::cout << "# Bureaucrat's copy assignment operator called" << std::endl;
	this->_is_signed = other._is_signed;
	return *this;
}

const std::string & Form::getName() const
{
	return _name;
}

const int & Form::getSignGrade() const
{
	return _sign_grade;
}

const int & Form::getExcuteGrade() const
{
	return _excute_grade;
}

const bool & Form::getSigned() const
{
	return _is_signed;
}

void Form::beSigned(const Bureaucrat & bu)
{
	try
	{
		if (_sign_grade < bu.getGrade())
			throw GradeTooHighException();
		_is_signed = true;
		std::cout <<bu.getName() << "signed "  << _name << "." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << bu.getName() << ", couldn’t sign " << _name 
		<< ", because " << e.what() << std::endl;
	}
}

std::ostream & operator << (std::ostream & out, const Form & fo)
{
	char c('X');
	if (fo.getSigned() == true)
		c = 'O';
	out << fo.getName() << ", <" << c << "> sign grade is " << fo.getSignGrade() 
	<< ", excute grade is " << fo.getExcuteGrade();
	return out;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Form's Grade is Too High!";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form's Grade is Too Low!";
}
