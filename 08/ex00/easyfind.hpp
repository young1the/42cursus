#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include "NoOccur.hpp"

template <typename T>
typename T::iterator easyfind(T & t, int value)
{
	typename T::iterator first = t.begin();
	typename T::iterator end = t.end();
	for (; first != end; ++first)
	{
		if (*first == value)
			return (first);
	}
	throw NoOccur();
}

#endif