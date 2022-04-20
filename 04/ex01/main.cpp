#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() 
{
	std::cout << "----------------------\n" << std::endl;

	std::cout << "<1>\n" << std::endl;
	Cat *original_cat = new Cat;
	{
		Cat copy_cat = *original_cat;
		original_cat->speak();
		copy_cat.speak();
		std::cout << "original cat learn Chur" << std::endl;
	}

	std::cout << "\n<2>\n" << std::endl;


	std::cout << "\n<3>\n" << std::endl;


	std::cout << "\n<4>\n" << std::endl;

	

	std::cout << "\n----------------------\n" << std::endl;



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