#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_excute_grade;

public:

	Form();
	Form(const Form & other);
	Form(const std::string & name_in, const int & sign_grade_in, const int & excute_grade_in);

	virtual ~Form();

	Form& operator = (const Form & other);
	/* occf */

	const std::string & getName() const;
	const int & getSignGrade() const;
	const int & getExcuteGrade() const;
	const bool & getSigned() const;

	void beSigned(const Bureaucrat & bu);
	virtual void execute(const Bureaucrat & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char * what() const throw();
	};
	class FormUnsignedException : public std::exception
	{
		const char * what() const throw();
	};
};

std::ostream & operator << (std::ostream & out, const Form & fo);

#endif