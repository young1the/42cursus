#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "# Cat's default constructor called" << std::endl;
	brain = new Brain;
	brain->setIdeas("Fish");
}

Cat::~Cat()
{
	std::cout << "# Cat's destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat & other)
: Animal(other)
{
	std::cout << "# Cat's copy constructor called" << std::endl;
	brain = new Brain;
	*this = other;
}

Cat& Cat::operator = (const Cat & other)
{
	std::cout << "# Cat's copy assignment operator called" << std::endl;
	*brain = *(other.brain);
	return *this;
}

/* occf end*/

void Cat::makeSound() const
{
	std::cout << "Cat : meow!" << std::endl;
}

void Cat::speak() const
{
	std::cout << brain->getIdeas()[0] << std::endl;
}

void Cat::eatChur()
{
	brain->setIdeas("Chur");
}