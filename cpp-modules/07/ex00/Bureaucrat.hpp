#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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

	class GradeTooHighException : public std::exception
	{
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char * what() const throw();
	};

	bool operator >(Bureaucrat b);
	bool operator <(Bureaucrat b);

};

std::ostream & operator << (std::ostream & out, const Bureaucrat & bu);

#endif