#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <exception>

class Span
{
	private:
	
	std::set<int>	_st;
	unsigned int	_max_size;
	unsigned int	_stored;

	public :

	Span(unsigned int N);
	void addNumber(int in);
	int shortestSpan() const;
	int longestSpan() const;
	
	class TheSpanIsFull : public std::exception
	{
		const char * what() const throw();
	};
	class NoSpanCanBeFound : public std::exception
	{
		const char * what() const throw();
	};

};

#endif