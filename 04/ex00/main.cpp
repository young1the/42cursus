#include "Dog.hpp"
#include "Cat.hpp"
#include "Fox.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	std::cout << "<1>\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal* fox = new Fox();

	std::cout << "\n<2>\n" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << fox->getType() << " " << std::endl;

	std::cout << "\n<3>\n" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	fox->makeSound();

	std::cout << "\n<4>\n" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete fox;

	std::cout << "\n----------------------\n" << std::endl;

	std::cout << "<1>\n" << std::endl;
	const WrongAnimal* wrmeta = new WrongAnimal();
	const WrongAnimal* wrcat = new WrongCat();
	const WrongAnimal* wrdog = new WrongDog();
	const WrongCat* wrcat2 = new WrongCat();

	std::cout << "\n<2>\n" << std::endl;
	std::cout << wrcat->getType() << " " << std::endl;
	std::cout << wrcat2->getType() << " " << std::endl;
	std::cout << wrdog->getType() << " " << std::endl;

	std::cout << "\n<3>\n" << std::endl;
	wrmeta->makeSound();
	wrcat->makeSound();
	wrcat2->makeSound();
	wrdog->makeSound();

	std::cout << "\n<4>\n" << std::endl;
	delete wrmeta;
	delete wrcat;
	delete wrcat2;
	delete wrdog;

	std::cout << "\n----------------------" << std::endl;

	return 0;
}