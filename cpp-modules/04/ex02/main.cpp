#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	std::cout << "<1>\n" << std::endl;
	// const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n<2>\n" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "\n<3>\n" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n<4>\n" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\n----------------------" << std::endl;

	return 0;
}