#include "Converter.hpp"

Converter::Converter()
: _input("Converter"), _type(NONE)
{
	std::cout << "# Converter's default constructor called" << std::endl;
}

Converter::~Converter()
{
	std::cout << "# Converter's destructor called" << std::endl;
}

Converter::Converter(const Converter & other)
: _input(other._input), _type(other._type)
{
	std::cout << "# Converter's copy constructor called" << std::endl;
}

Converter& Converter::operator = (const Converter & other)
{
	std::cout << "# Converter's copy assignment operator called" << std::endl;
	_input = other._input;
	_type = other._type;
	return *this;
}

Converter::Converter(const char *arg)
: _input(arg)
{
	_type = detectType();
	std::cout << "# Converter's constructor called" << std::endl;
}

/* occf */

const char * Converter::PseudoLiteral::what() const throw()
{
	return "PseudoLiteral";
}

const char * Converter::Impossible::what() const throw()
{
	return "impossible";
}

const char * Converter::NonDisplayable::what() const throw()
{
	return " Non displayable";
}

/* exceptions */

TypeStr Converter::detectType()
{
	if (isPseudo())
		return PSEUDO;
	unsigned int i = 0;
	bool f = false;
	bool dot = false;
	if (_input.front() == '+' || _input.front() == '-')
		i = 1;
	if (_input.back() == 'f')
	{
		f = true;
		_input.pop_back();
	}
	while (i < _input.size())
	{
		if (_input[i] == '.')
		{
			if (dot == false)
				dot = true;
			else
				break ;
		}
		else if (std::isdigit(_input[i]) == false)
			break ;
		i++;
	}
	if (i == _input.size())
	{
		if (dot == false)
			return INT;
		else if (dot == true && f == true)
			return FLOAT;
		else
			return DOUBLE;
	}
	return NONE;
}

bool Converter::isPseudo()
{
	if (_input == "inf" || _input == "+inf" || _input == "-inf" || _input == "nan")
		return true;
	return false;
}

/* util constructer */

char	Converter::getChar() const
{
	try
	{
		int i = getInt();
		if (i > std::numeric_limits<char>::max()
			|| i < std::numeric_limits<char>::min())
			throw Impossible();
		if (std::isprint(i) == false)
			throw NonDisplayable();
		return (static_cast<char>(i));
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

int		Converter::getInt() const
{
	if (_type > DOUBLE)
		throw Impossible();
	else if (_type > INT)
	{
		try
		{
			double d = getDouble();
			if (d > std::numeric_limits<int>::max()
				|| d < std::numeric_limits<int>::min())
				throw Impossible();
			return (static_cast<int>(d));
		}
		catch (std::exception & e)
		{
			throw ;
		}
	}
	else
	{
		std::stringstream ss(_input);
		int ret;
		ss >> ret;
		if (ss.fail())
			throw Impossible();
		return (ret);
	}
}

float	Converter::getFloat() const
{
	try
	{
		double d = getDouble();
		if (d > std::numeric_limits<float>::max() 
		|| d < -std::numeric_limits<float>::max())
			throw Impossible();
		return (static_cast<float>(d));
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

double	Converter::getDouble() const
{
	if (_type == PSEUDO)
		throw PseudoLiteral();
	if (_type == NONE)
		throw Impossible();
	std::stringstream ss(_input);
	double ret;
	ss >> ret;
	if (ss.fail())
		throw Impossible();
	return (ret);
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

	out << "float : ";
	try
	{
		out << c.getFloat() << "f";
	}
	catch (Converter::PseudoLiteral & e)
	{
		out << c.getInput() << "f";
	}
	catch (std::exception & e)
	{
		out << e.what();
	}
	out << std::endl;

	out << "double : ";
	try
	{
		out << c.getDouble();
	}
	catch (Converter::PseudoLiteral & e)
	{
		out << c.getInput();
	}
	catch (std::exception & e)
	{
		out << e.what();
	}
	return out;
}
