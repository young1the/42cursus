#include <iostream>

#include "Iter.hpp"
#include "print.hpp"
#include "toLower.hpp"

#include <vector>

int main()
{
	int ia[3] = {2, 7, 42};
	Iter<int>(ia, 3, print);
	std::cout << std::endl;

	char ca[7] = {'4','2','S','E','O','u','L'};
	Iter<char>(ca, 7, print);
	std::cout << std::endl;
	Iter<char>(ca, 7, toLower);
	Iter<char>(ca, 7, print);
	std::cout << std::endl;

}