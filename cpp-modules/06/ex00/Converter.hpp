#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <limits>

enum TypeStr
{
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	NONE,
};

class Converter {

private:

	std::string		_input;
	enum TypeStr	_type;

public:

	Converter();
	~Converter();
	Converter(const Converter & other);
	Converter& operator = (const Converter & other);

	Converter(const char *arg);
	/* occf */

	class NonDisplayable : public std::exception
	{
		const char * what() const throw();
	};
	class PseudoLiteral : public std::exception
	{
		const char * what() const throw();
	};
	class Impossible : public std::exception
	{
		const char * what() const throw();
	};

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;
	int		getValid() const;
	const std::string & getInput() const;

	TypeStr detectType();
	bool	isPseudo();

};

std::ostream & operator << (std::ostream & out, const Converter & c);

#endif
