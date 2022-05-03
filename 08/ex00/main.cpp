#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include "easyfind_tester.hpp"

int main()
{
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> lst;
	std::cout << "<vector>----------------------------------" << std::endl;
	easyfind_tester(vec);
	std::cout << "<deque>-----------------------------------" << std::endl;
	easyfind_tester(deq);
	std::cout << "<list>------------------------------------" << std::endl;
	easyfind_tester(lst);
	std::cout << "------------------------------------------" << std::endl;
}