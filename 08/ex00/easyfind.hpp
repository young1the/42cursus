#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T & t, int value)
{
	typename T::iterator first = t.begin();
	typename T::iterator last = t.end();
	for (; first != last; ++first)
	{
		if (*first == value)
			return (first);
	}
	return last;
}

#endif