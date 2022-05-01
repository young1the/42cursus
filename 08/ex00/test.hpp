#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

template<typename T>
void easyfind_tester(T & t)
{
	std::cout << "# push (3), (6), (9) in Container" << std::endl;
	t.push_back(3);
	t.push_back(6);
	t.push_back(9);
	typename T::iterator iter;
	std::cout << "# easy find (3)" << std::endl;
	iter = easyfind(t, 3);
	(iter != std::end(t)) ?
	std::cout << "found the first occurrence. -> " << *iter << std::endl
	: std::cout << "no occurrence is found!" << std::endl;
	std::cout << "# easy find (42)" << std::endl;
	iter = easyfind(t, 42);
	(iter != std::end(t)) ?
	std::cout << "found the first occurrence. -> " << *iter << std::endl
	: std::cout << "no occurrence is found!" << std::endl;
}

#endif