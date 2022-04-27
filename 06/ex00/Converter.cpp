#include "Converter.hpp"

Converter::Converter()
: _input("Converter"), _valid(END), _value_i(0), _value_d(0)
{
	std::cout << "# Converter's default constructor called" << std::endl;
}

Converter::~Converter()
{
	std::cout << "# Converter's destructor called" << std::endl;
}

Converter::Converter(const Converter & other)
: _input(other._input), _valid(other._valid),
_value_i(other._value_i), _value_d(other._value_d)
{
	std::cout << "# Converter's copy constructor called" << std::endl;
}

Converter& Converter::operator = (const Converter & other)
{
	std::cout << "# Converter's copy assignment operator called" << std::endl;
	this->_input = other._input;
	this->_valid = other._valid;
	this->_value_d = other._value_d;
	this->_value_i = other._value_i;
	return *this;
}

Converter::Converter(const char *arg)
: _input(arg), _value_i(0), _value_d(0)
{
	std::cout << "# Converter's constructor called" << std::endl;
	if (_input == "nan")
		_valid = NOTANUM;
	else if (_input == "+inf" || _input == "-inf" || _input == "+inff" || _input == "-inff")
		_valid = INFINI;
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
		throw Impossible();
	errno = 0;
	int i;
	i = std::strtol(_input.c_str(), NULL, 10);
	if (errno == ERANGE)
		throw Impossible();
	if (_value_i > CHAR_MAX
	|| _value_i < CHAR_MIN)
		throw Impossible();
	if (!std::isprint(_value_i))
		throw NonDisplayable();
	return (static_cast<char>(_value_i));
}

int		Converter::getInt() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible();
	errno = 0;
	int i;
	i = std::strtol(_input.c_str(), NULL, 10);
	if (errno == ERANGE)
		throw Impossible();
	return (_value_i);
}

float	Converter::getFloat() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible();
	errno = 0;
	float f;
	f = std::strtof(_input.c_str(), NULL);
	if (errno == ERANGE)
		throw Impossible();
	return (static_cast<float>(_value_d));
}

double	Converter::getDouble() const
{
	if (_valid >= IMPOSSIBLE)
		throw Impossible();
	errno = 0;
	double d;
	d = std::strtod(_input.c_str(), NULL);
	if (errno == ERANGE)
		throw Impossible();
	return (_value_d);
}

const std::string & Converter::getInput() const
{
	return _input;
}


std::ostream & operator << (std::ostream & out, const Converter & c)
{
	out << "char : ";
	try
	{
		std::string str = "'";
		str.push_back(c.getChar());
		str.push_back('\'');
		out << str;
	}
	catch (std::exception & e)
	{
		out << e.what();
	}
	out << std::endl;
	// ##### char

	out << "int : ";
	try
	{
		out << c.getInt();
	}
	catch (std::exception & e)
	{
		out << e.what();
	}
	out << std::endl;
	// ##### int

	out << "float : ";
	try
	{
		out << c.getFloat() << "f";
	}
	catch (std::exception & e)
	{
		switch (c.getValid())
		{
		case IMPOSSIBLE:
			out << e.what();
			break;
		default:
			out << c.getInput() << "f";
			break;
		}
	}
	out << std::endl;
	// ##### float

	out << "double : ";
	try
	{
		out << c.getDouble();
	}
	catch (std::exception & e)
	{
		switch (c.getValid())
		{
		case IMPOSSIBLE:
			out << e.what();
			break;
		default:
			out << c.getInput();
			break;
		}
	}
	return out;
}
