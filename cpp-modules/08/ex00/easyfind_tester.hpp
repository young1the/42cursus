#ifndef EASYFIND_TESTER_HPP
#define EASYFIND_TESTER_HPP

#include <iostream>
#include "easyfind.hpp"

template<typename T>
void easyfind_tester(T & t)
{
	typename T::iterator iter;
	std::cout << "tester : push (3), (6), (9) in Container" << std::endl;
	t.push_back(3);
	t.push_back(6);
	t.push_back(9);
	std::cout << "tester : easyfind (3)" << std::endl;
	try
	{
		iter = easyfind(t, 3);
		std::cout << "tester : found the first occurrence. -> " << *iter << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "tester : easyfind (42)" << std::endl;
	try
	{
		iter = easyfind(t, 42);
		std::cout << "found the first occurrence. -> " << *iter << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

#endif