#include "Span.hpp"

Span::Span()
: _max_size(0){}

Span::Span(unsigned int N)
: _max_size(N){}

Span::Span(const Span & other)
{
	*this = other;
}

Span & Span::operator = (const Span & other)
{
	this->_st = other._st;
	this->_max_size = other._max_size;
	return *this;
}

void Span::addNumber(int in)
{
	if (_st.size() == _max_size)
		throw TheSpanIsFull();
	_st.insert(in);
}

size_t Span::shortestSpan() const
{
	if (_st.size() < 2)
		throw NoSpanCanBeFound();
	size_t ret = longestSpan();
	std::set<int>::iterator first = _st.begin();
	std::set<int>::iterator next = first;
	while (++next != _st.end())
	{
		size_t diff = abs(*next - *first);
		if (diff < ret)
			ret = diff;
		++first;
	}
	return ret;
}

size_t Span::longestSpan() const
{
	if (_st.size() < 2)
		throw NoSpanCanBeFound();
	return abs(*(--_st.end()) - *(_st.begin()));
}

const char * Span::TheSpanIsFull::what() const throw()
{
	return "The Span is full!";
}

const char * Span::NoSpanCanBeFound::what() const throw()
{
	return "No Span can be found!";
}
