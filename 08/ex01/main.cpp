#include <iostream>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(4);
		sp.addNumber(0);
		sp.addNumber(100);
		sp.addNumber(11);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
	}
	try
	{
		Span sp = Span(1);
		sp.addNumber(0);
		std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "! " << e.what() << std::endl;
	}
	try
	{
		Span sp = Span(3);
		sp.addNumber(0);
		sp.addNumber(100);
		sp.addNumber(11);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "! " << e.what() << std::endl;
	}

	return 0;
}