#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;

	std::cout << "\n----------------------\n" << std::endl;

	Animal *animal_array[3];
	animal_array[0] = new Dog();
	animal_array[1] = new Cat();
	animal_array[2] = new Cat();
	for (int i = 0; i < 3; ++i)
	{
		animal_array[i]->makeSound();
	}
	for (int i = 0; i < 3; ++i)
	{
		delete animal_array[i];
	}

	std::cout << "\n----------------------" << std::endl;
	return 0;
}