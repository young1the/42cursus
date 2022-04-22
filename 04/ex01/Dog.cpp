#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "# Dog's default constructor called" << std::endl;
	brain = new Brain;
	brain->setIdeas("Ball");
}

Dog::~Dog()
{
	std::cout << "# Dog's destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog & other)
: Animal(other)
{
	std::cout << "# Dog's copy constructor called" << std::endl;
	brain = new Brain;
	*this = other;
}

Dog& Dog::operator = (const Dog & other)
{
	std::cout << "# Dog's copy assignment operator called" << std::endl;
	*brain = *(other.brain);
	return *this;
}

/* occf end*/

void Dog::makeSound() const
{
	std::cout << "Dog : woof-woof!" << std::endl;
}
