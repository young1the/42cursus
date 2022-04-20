#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n----------------------\n" << std::endl;

	Cat *cat = new Cat();
	cat->setIdeas("Fish");
	Cat copy_cat = *cat;
	delete cat;
	std::cout << copy_cat.getIdea() << std::endl;

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