#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {

private:

	const std::string	_name;
	int					_grade;

public:

	Bureaucrat();
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat(const std::string & name_in, const int & grade_in);

	~Bureaucrat();

	Bureaucrat& operator = (const Bureaucrat & other);
	/* occf */

	const std::string & getName() const;
	const int & getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form & fo);
	void executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char * what() const throw();
	};

};

std::ostream & operator << (std::ostream & out, const Bureaucrat & bu);

#endif