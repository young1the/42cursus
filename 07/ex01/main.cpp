#include <iostream>
#include <cstdlib>

#include "Iter.hpp"

template<typename T>
void print(T a)
{
	std::cout << a << " ";
}

void toLower(char &c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 'a' - 'A';
	}
}

int main()
{
	int i[3] = {2, 7, 42};
	Iter<int>(i, 3, print);
	std::cout << std::endl;

	char c[7] = {'4','2','S','e','O','u','L'};
	Iter<char>(c, 7, print);
	std::cout << std::endl;
	
	Iter<char>(c, 7, toLower);
	Iter<char>(c, 7, print);
	std::cout << std::endl;
}