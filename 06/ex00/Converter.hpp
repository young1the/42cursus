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
	INFINI,
	NOTANUM,
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

std::ostream & operator << (std::ostream & out, const Converter & c);

#endif
