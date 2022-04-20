#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "# Cat's default constructor called" << std::endl;
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
	(void)other;
	return *this;
}

/* occf end*/

void Cat::makeSound() const
{
	std::cout << "Cat : meow!" << std::endl;
}
