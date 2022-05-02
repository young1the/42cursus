#include "Span.hpp"

Span::Span(unsigned int N)
: _max_size(N), _stored(0)
{
}

void Span::addNumber(int in)
{
	if (_stored == _max_size)
		throw TheSpanIsFull();
	_st.insert(in);
	_stored++;
}

int Span::shortestSpan() const
{
	if (_stored < 2)
		throw NoSpanCanBeFound();
	int ret = longestSpan();
	for (std::set<int>::iterator sit = _st.begin(); sit != --_st.end(); ++sit)
	{
		std::set<int>::iterator bigger_sit = sit;
		++bigger_sit;
		if (((*bigger_sit - *sit) < ret))
			ret = *bigger_sit - *sit;
	}
	return ret;
}

int Span::longestSpan() const
{
	if (_stored < 2)
		throw NoSpanCanBeFound();
	return *(--_st.end()) - *(_st.begin());
}

const char * Span::TheSpanIsFull::what() const throw()
{
	return "The Span is full!";
}

const char * Span::NoSpanCanBeFound::what() const throw()
{
	return "No Span can be found!";
}
