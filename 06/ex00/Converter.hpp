#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include <cerrno>

enum PseudoLiterals
{
	VALID,
	NONDISPLAYABLE,
	IMPOSSIBLE,
	INFINITY,
	NAN,
	END
};

class Converter {

private:

	std::string			_input;
	enum PseudoLiterals	_valid;
	int					_value_i;
	double				_value_d;

public:

	Converter();
	~Converter();
	Converter(const Converter & other);
	Converter& operator = (const Converter & other);

	Converter(const char *arg);
	/* occf */

	class Impossible : public std::exception
	{
		const char * what() const throw();
	};
	class NonDisplayable : public std::exception
	{
		const char * what() const throw();
	};

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;
	int		getValid() const;
	const std::string & getInput() const;

};

Converter::Converter()
: _input("Converter"), _valid(5), _value_i(0), _value_d(0)
{
	std::cout << "# Converter's default constructor called" << std::endl;
}

Converter::~Converter()
{
	std::cout << "# Converter's destructor called" << std::endl;
}

Converter::Converter(const Converter & other)
: _input(other._input), _valid(other._valid)
{
	std::cout << "# Converter's copy constructor called" << std::endl;
}

Converter& Converter::operator = (const Converter & other)
{
	std::cout << "# Converter's copy assignment operator called" << std::endl;
	this->_input = other._input;
	this->_valid = other._valid;
	return *this;
}

Converter::Converter(const char *arg)
: _input(arg), _value_i(0), _value_d(0)
{
	std::cout << "# Converter's constructor called" << std::endl;
	if (_input == "nan")
		_valid = NAN;
	else if (_input == "+inf" || _input == "-inf" || _input == "+inff" || _input == "-inff")
		_valid = INFINITY;
	else if (!std::isdigit(_input[0]) && _input[0] != '+' && _input[0] != '-')
		_valid = IMPOSSIBLE;
	else
	{
		char *endptr = NULL;
		_value_d = std::strtod(_input.c_str(), &endptr);
		std::string str = endptr;
		if (str.length() == 1 && str.back() == 'f')
			_valid = VALID;
		else if (str.length() == 0)
			_valid = VALID;
		else
			_valid = IMPOSSIBLE;
		_value_i = std::strtol(_input.c_str(), NULL, 10);
}

/* occf */

const char * Converter::Impossible::what() const throw()
{
	return "Impossible";
}

const char * Converter::NonDisplayable::what() const throw()
{
	return " Non displayable";
}

int		Converter::getValid() const
{
	return _valid;
}

char	Converter::getChar() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible;
	if (_value_i > CHAR_MAX
	|| _value_i < CHAR_MIN)
		throw Impossible;
	if (!std::isprint(_value_i))
		throw NonDisplayable;
	return (static_cast<char>(_value_i));
}

int		Converter::getInt() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible();
	errno = 0;
	_value_i = std::strtol(_input.c_str(), NULL, 10);
	if (errno == ERANGE)
		throw Impossible();
	return (static_cast<int>(_value_i));
}

float	Converter::getFloat() const
{
	if (_valid >= IMPOSSIBLE)
		throw IMPOSSIBLE();
	errno = 0;
	_value_d = std::strtof(_input.c_str(), NULL, 10);
	if (errno == ERANGE)
		throw Impossible();
	return (static_cast<float>(_value_d));
}

double	Converter::getDouble() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible();
	errno = 0;
	_value_d = std::strtod(_input.c_str(), NULL, 10);
	if (errno == ERANGE)
		throw Impossible();
	return (static_cast<double>(_value_d));
}

const std::string & getInput() const
{
	return _input;
}


std::ostream & operator << (std::ostream & out, const Converter & c)
{
	out << "char : ";
	try
	{
		out << getChar();
		out << endl;
	}
	catch (std::exception & e)
	{
		out << e.what << std::endl;
	}
	// char

	out << "int : ";
	try
	{
		out << getInt();
		out << endl;
	}
	catch (std::exception & e)
	{
		out << e.what << std::endl;
	}
	// int

	out << "float : ";
	try
	{
		out << getfloat();
	}
	catch (std::exception & e)
	{
		switch (c.getValid())
		{
		case IMPOSSIBLE:
			out << e.what() << std::endl;
		default:
			out << _input;
			break;
		}
	}
	out << "f" << endl;
	// float

	out << "double : ";
	try
	{
		out << getDouble()
		out << std::endl;
	}
	catch (std::exception & e)
	{
		switch (c.getValid())
		{
		case IMPOSSIBLE:
			out << e.what() << std::endl;
		default:
			out << _input << std::endl;;
			break;
		}
	}
}

#endif
