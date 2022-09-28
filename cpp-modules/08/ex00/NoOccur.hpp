#ifndef NOOCCUR_HPP
#define NOOCCUR_HPP

#include <exception>

class NoOccur : public std::exception
{
	const char * what() const throw();
};

#endif