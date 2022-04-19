#include "Animal.hpp"

Animal::Animal()
: type("default")
{
	std::cout << "# Animal's default constructor called" << std::endl;
	brain = new Brain;
}

Animal::~Animal()
{
	std::cout << "# Animal's destructor called" << std::endl;
	delete brain;
}

Animal::Animal(const Animal & other)
: type(other.type)
{
	std::cout << "# Animal's copy constructor called" << std::endl;
	brain = new Brain;
	*(brain) = *(other.brain);
}

Animal& Animal::operator = (const Animal & other)
{
	std::cout << "# Animal's copy assignment operator called" << std::endl;
	this->type = other.type;
	brain = new Brain;
	*brain = *(other.brain);
	return *this;
}

/* occf end*/

const std::string &	Animal::getType() const
{
	return type;
}

void			Animal::makeSound() const
{
	std::cout << "?????" << std::endl;
}

void			Animal::setIdeas(std::string idea_in)
{
	brain->setIdeas(idea_in);
}

const std::string &	Animal::getIdea() const
{
	return (brain->getIdea());
}
