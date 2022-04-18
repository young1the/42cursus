#include "Cat.hpp"

Cat::Cat()
: Animal()
{
	std::cout << "# Cat's default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "# Cat's destructor called" << std::endl;
}

Cat::Cat(const Cat & other)
: Animal(other)
{
	std::cout << "# Cat's copy constructor called" << std::endl;
}

Cat& Cat::operator = (const Cat & other)
{
	std::cout << "# Cat's copy assignment operator called" << std::endl;
	Animal::operator =(other);
	return *this;
}

/* occf end*/

void Cat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}
