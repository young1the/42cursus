#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	Cat *original_cat = new Cat;
	std::cout << "---original_cat constructed---" << std::endl;
	{
		Cat copy_cat = *original_cat;
		std::cout << "---copy_cat copied---" << std::endl;
		original_cat->speak();
		copy_cat.speak();
		std::cout << "--original_cat Chur--" << std::endl;
		original_cat->eatChur();
		original_cat->speak();
		copy_cat.speak();
	}
	std::cout << "--copy_cat gone, out of scope--" << std::endl;
	original_cat->speak();
	std::cout << "--delete original_cat--" << std::endl;
	delete original_cat;

	std::cout << "\n----------------------\n" << std::endl;

	Animal *animal_array[10];
	for (int i(0); i < 10; ++i)
	{
		std::cout << "iter " << i << std::endl;
		if (i % 2 == 0)
			animal_array[i] = new Cat;
		else
			animal_array[i] = new Dog;
		animal_array[i]->makeSound();
	}
	for (int i(0); i < 10; ++i)
	{
		delete animal_array[i];
	}

	std::cout << "\n----------------------" << std::endl;

	while(42)
	{
		std::string in;
		getline(std::cin, in);
		if (in == "EXIT")
			break ;
	}

	return 0;
}