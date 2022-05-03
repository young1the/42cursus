#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <exception>
#include <algorithm>

class Span
{
	private:
	
	std::multiset<int>	_st;
	unsigned int	_max_size;

	public :

	Span();
	Span(unsigned int N);
	Span(const Span & other);
	Span & operator = (const Span & other);

	void addNumber(int in);
	size_t shortestSpan() const;
	size_t longestSpan() const;
	
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