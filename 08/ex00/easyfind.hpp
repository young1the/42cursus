#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include "NoOccur.hpp"

template <typename T>
typename T::iterator easyfind(T & t, int value)
{
	typename T::iterator ret = std::find(t.begin(), t.end(), value);
	if (ret == t.end())
		throw NoOccur();
	else
		return ret;
}

#endif