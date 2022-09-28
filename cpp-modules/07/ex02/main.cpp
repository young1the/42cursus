#include <iostream>
#include "Array.hpp"
#include <string>
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
		std::cout << ">> Array [tmp], [test] copy constructed" << std::endl;		
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (i % 250 == 0)
				std::cout << "tmp : " << tmp[i] << " | numbers : " << numbers[i]<< " | test : " << test[i] << std::endl;
		}
		std::cout << ">> change tmp[0] -> 42, \n";
		tmp[0] = 42;
		std::cout << "tmp : " << tmp[0] << " | numbers : " << numbers[0]<< " | test : " << test[0] << std::endl;
	}
	std::cout << ">> Array [tmp], [test] destructed (out of scope)." << std::endl;
	std::cout << ">> compare int array mirror and Array numbers" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (i % 75 == 0)
			std::cout << "mirror : "<< mirror[i] << " | number : " << numbers[i] << std::endl;
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << ">> numbers[-2] = 0; expecting exception" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "! " << e.what() << '\n';
	}
	std::cout << ">> numbers[MAX_VAL] = 0; expecting exception" << std::endl;
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
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (i % 75 == 0)
			std::cout << "mirror : "<< mirror[i] << " | number : " << numbers[i] << std::endl;
	}
	delete [] mirror; //

	Array<std::string> strarr_empty;
	std::cout << &strarr_empty << std::endl;
	std::string *strarr = new std::string[0];
	std::cout << strarr << std::endl;

	return 0;
}