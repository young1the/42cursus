#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << ">> Array [numbers] constructed" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << ">> Array [tmp], [test] destructed (out of scope)." << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (i % 75 == 0)
			std::cout << mirror[i] << " " << numbers[i] << std::endl;
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << ">> expecting exception" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "! " << e.what() << '\n';
	}
	std::cout << ">> expecting exception" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "! " << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror; //
	return 0;
}