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
		if (dot == false && f == false)
			return INT;
		else if (dot == true && f == true)
			return FLOAT;
		else if (dot == true && f == false)
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
		switch (_type)
		{
			case INT :
			{
				int i = getInt();
				if (i > std::numeric_limits<char>::max()
					|| i < std::numeric_limits<char>::min())
					throw Impossible();
				if (std::isprint(i) == false)
					throw NonDisplayable();
				return (static_cast<char>(i));
			}
			case FLOAT :
			{
				float f = getFloat();
				if (f > std::numeric_limits<char>::max()
					|| f < std::numeric_limits<char>::min())
					throw Impossible();
				if (std::isprint(f) == false)
					throw NonDisplayable();
				return (static_cast<char>(f));
			}
			case DOUBLE :
			{
				double d = getDouble();
				if (d > std::numeric_limits<char>::max()
					|| d < std::numeric_limits<char>::min())
					throw Impossible();
				if (std::isprint(d) == false)
					throw NonDisplayable();
				return (static_cast<char>(d));
			}
			default :
				throw Impossible();
		}
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

int		Converter::getInt() const
{
	try
	{
		switch (_type)
		{
			case INT :
			{
				std::stringstream ss(_input);
				int ret;
				ss >> ret;
				if (ss.fail())
					throw Impossible();
				return (ret);
			}
			case FLOAT :
			{
				float f = getFloat();
				if (f > std::numeric_limits<int>::max()
					|| f < std::numeric_limits<int>::min())
					throw Impossible();
				return (static_cast<int>(f));
			}
			case DOUBLE :
			{
				double d = getDouble();
				if (d > std::numeric_limits<int>::max()
					|| d < std::numeric_limits<int>::min())
					throw Impossible();
				return (static_cast<int>(d));
			}
			default :
				throw Impossible();
		}
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

float	Converter::getFloat() const
{
	try
	{
		switch (_type)
		{
			case INT :
			{
				int i = getInt();
				return (static_cast<float>(i));
			}
			case FLOAT :
			{
				std::stringstream ss(_input);
				float ret;
				ss >> ret;
				if (ss.fail())
					throw Impossible();
				return (ret);
			}
			case DOUBLE :
			{
				double d = getDouble();
				if (d > std::numeric_limits<float>::max()
					|| d < -std::numeric_limits<float>::max())
					throw Impossible();
				if (d != 0)
				{
					if (fabs(d) < fabs(std::numeric_limits<float>::min()))
						throw Impossible();
				}
				return (static_cast<float>(d));
			}
			case PSEUDO :
				if (_type == PSEUDO)
					throw PseudoLiteral();
			default :
				throw Impossible();
		}
	}
	catch (std::exception & e)
	{
		throw ;
	}
}

double	Converter::getDouble() const
{
	try
	{
		switch (_type)
		{
			case INT :
			{
				int i = getInt();
				return (static_cast<double>(i));
			}
			case FLOAT :
			{
				float f = getFloat();
				return (static_cast<double>(f));
			}
			case DOUBLE :
			{
				std::stringstream ss(_input);
				double ret;
				ss >> ret;
				if (ss.fail())
					throw Impossible();
				return (ret);
			}
			case PSEUDO :
				if (_type == PSEUDO)
					throw PseudoLiteral();
			default :
				throw Impossible();
		}
	}
	catch (std::exception & e)
	{
		throw ;
	}
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
		if (c.getInput() == "inf")
			out << '+';
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
		if (c.getInput() == "inf")
			out << '+';
		out << c.getInput();
	}
	catch (std::exception & e)
	{
		out << e.what();
	}
	return out;
}
