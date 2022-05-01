#include <iostream>
#include "easyfind.hpp"
#include "test.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> lst;
	std::cout << "<vector>--------------------------" << std::endl;
	easyfind_tester(vec);
	std::cout << "<deque>---------------------------" << std::endl;
	easyfind_tester(deq);
	std::cout << "<list>----------------------------" << std::endl;
	easyfind_tester(lst);
	std::cout << "---------------------------------" << std::endl;
}