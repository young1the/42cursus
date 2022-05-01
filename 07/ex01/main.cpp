#include <iostream>

#include "Iter.hpp"
#include "print.hpp"
#include "toLower.hpp"

int main()
{
	int is[3] = {2, 7, 42};
	Iter<int>(is, 3, print);
	std::cout << std::endl;

	char cs[7] = {'4','2','S','E','O','u','L'};
	Iter<char>(cs, 7, print);
	std::cout << std::endl;
	Iter<char>(cs, 7, toLower);
	Iter<char>(cs, 7, print);
	std::cout << std::endl;
}